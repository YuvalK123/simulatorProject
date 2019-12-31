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
  int retValue = 5, i = 1;
  string str = *(it + i);
  while (str != "{") {
    operate op = retOp(str);
    if (op == N) {
      i++;
      str = *(it + i);
    } else {
      string left = *(it + (i - 1));
      string right = *(it + (i + 1));
      switch (op) {
        case (SMALLER):
//          cout<<"condition is:"<<endl<<"left: "<<left<<" op is smaller, "<<" right is "<<right<<endl;
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
  return retValue;
}

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
  int retValue = 0, ind;
  while (str != "}") {
    Command *c = helper->getCommandMap()[str];
    if (c != nullptr) {
      ind = c->execute(it);
      retValue += ind;
      it += ind;
    }
  }
  retValue++;
  return retValue;
}

#endif //SIMULATORPROJECT_COMMANDS_CONDITIONPARSER_H_
