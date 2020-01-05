//
// Created by yuval Kasner on 20/12/19.
//

#ifndef SIMULATORPROJECT_COMMANDS_CONDITIONPARSER_H_
#define SIMULATORPROJECT_COMMANDS_CONDITIONPARSER_H_
#include "Command.h"
#include "../SimulatorHelper.h"
class ConditionParser : public Command {
 private:
  enum operate { SMALLER, BIGGER, SE, BE, EQ, NE, N };
  operate retOp(string str);
  string getArithmetic(string left, string right, const char *arithmetic);
 protected:
  int bracketsCommands(vector<string>::iterator it);
  volatile bool condition = false;
  vector<Command *> commands;
 public:
  int setCondition(vector<string>::iterator it);
  explicit ConditionParser() = default;
  int execute(vector<string>::iterator it) override = 0;
};

string ConditionParser::getArithmetic(string left, string right, const char *arithmetic) {
  string arith;
  if (strcmp(arithmetic, "<") == 0) {
    arith = "smaller";
  } else if (strcmp(arithmetic, ">") == 0) {
    arith = "bigger";
  } else if (strcmp(arithmetic, ">=") == 0) {
    arith = "biggerEq";
  } else if (strcmp(arithmetic, "<=") == 0) {
    arith = "smallerEq";
  } else if (strcmp(arithmetic, "==") == 0) {
    arith = "Equal";
  }

  return arith;
}

int ConditionParser::setCondition(vector<string>::iterator it) {

  int ret = 1, expStart = 0;
  string currentStr = *(it + ret), left, right, oper;
  while (currentStr != "{") {
    if (retOp(currentStr) != N) {
      oper = currentStr;
      expStart = ret;
      ret++;
      currentStr = *(it + ret);
      continue;
    }
    if (expStart == 0) {
      left += currentStr;
    } else {
      right += currentStr;
    }
    ret++;
    currentStr = *(it + ret);
  }
  ret++;
  operate op = retOp(oper);
//  cout << "if " << left << " " << oper << " " << right << endl;
  switch (op) {
    case (SMALLER):
      this->condition = helper->getInterpret()->interpret(left)->calculate() <
          helper->getInterpret()->interpret(right)->calculate();
      break;
    case (BIGGER):
      this->condition = helper->getInterpret()->interpret(left)->calculate() >
          helper->getInterpret()->interpret(right)->calculate();
      break;
    case (SE):
      this->condition = helper->getInterpret()->interpret(left)->calculate() <=
          helper->getInterpret()->interpret(right)->calculate();
      break;
    case (BE):
      this->condition = helper->getInterpret()->interpret(left)->calculate() >=
          helper->getInterpret()->interpret(right)->calculate();
      break;
    case (EQ):
      this->condition = helper->getInterpret()->interpret(left)->calculate() ==
          helper->getInterpret()->interpret(right)->calculate();
      break;
    case (NE):
      this->condition = helper->getInterpret()->interpret(left)->calculate() !=
          helper->getInterpret()->interpret(right)->calculate();
      break;
    default:break;
  }
  return ret;
}
/*
  string str = *(it + i);
  while (str != "{") {
    operate op = retOp(str);
    if (op == N) {
      i++;
      str = *(it + i);
    } else {
      string left = *(it + (i - 1));
      string right = *(it + (i + 1));
      cout<<"if "<<left<<" "<<str<<" "<< right<<endl;
      switch (op) {
        case (SMALLER):
          this->condition = helper->getInterpret()->interpret(left)->calculate() <
              helper->getInterpret()->interpret(right)->calculate();
          break;
        case (BIGGER):
          this->condition = helper->getInterpret()->interpret(left)->calculate() >
              helper->getInterpret()->interpret(right)->calculate();
          break;
        case (SE):
          this->condition = helper->getInterpret()->interpret(left)->calculate() <=
              helper->getInterpret()->interpret(right)->calculate();
          break;
        case (BE):
          this->condition = helper->getInterpret()->interpret(left)->calculate() >=
              helper->getInterpret()->interpret(right)->calculate();
          break;
        case (EQ):
          this->condition = helper->getInterpret()->interpret(left)->calculate() ==
              helper->getInterpret()->interpret(right)->calculate();
          break;
        case (NE):
          this->condition = helper->getInterpret()->interpret(left)->calculate() !=
              helper->getInterpret()->interpret(right)->calculate();
          break;
        default:break;
      }
      break;
    }
  }
  cout<<"next is "<<*(it + ret)<<endl;
  return ret;
}*/

ConditionParser::operate ConditionParser::retOp(string str) {
  if (str == "<") {
    return SMALLER;
  }
  if (str == ">") {
    return BIGGER;
  }
  if (str == "<=") {
    return SE;
  }
  if (str == ">=") {
    return BE;
  }
  if (str == "==") {
    return EQ;
  }
  if (str == "!=") {
    return NE;
  }
  return N;
}

int ConditionParser::bracketsCommands(vector<string>::iterator it) {
  string str = *(it);
  int ind = 0;
  while (str != "}") {
    Command *c = helper->getCommandMap()[str];
    if (c != nullptr) {
      ind += c->execute(it + ind);
    } else {
      c = helper->getCommandMap()["var"];
      try {
        ind += c->execute(it + ind);
      }
      catch (const char *e) {
        cerr << e << endl;
      }
    }
    str = *(it + ind);
  }
  ind++;
  return ind;
}

#endif //SIMULATORPROJECT_COMMANDS_CONDITIONPARSER_H_
