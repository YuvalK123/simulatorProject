//
// Created by yuval Kasner on 20/12/19.
//

#ifndef SIMULATORPROJECT_COMMANDS_CONDITIONPARSER_H_
#define SIMULATORPROJECT_COMMANDS_CONDITIONPARSER_H_
#include "Command.h"
#include "SimulatorHelper.h"
class ConditionParser : public Command {
 private:
  enum operate { SMALLER, BIGGER, SE, BE, EQ, NE, N };
  operate retOp(string str);
 protected:
  int bracketsCommands(vector<string>::iterator it);
  volatile bool condition = false;
 public:
  int setCondition(vector<string>::iterator it);
  explicit ConditionParser() = default;
  int execute(vector<string>::iterator it) override = 0;
};
/**
 *method sets condition - if true or false.
 * @param it iterator of parser
 * @return number of steps to jump at iterator = how many strings were in the condition part (including ")
 */
int ConditionParser::setCondition(vector<string>::iterator it) {
  int ret = 1, expStart = 0;
  string currentStr = *(it + ret), l, r, oper;
  while (currentStr != "{") { //get full 1 operator condition
    if (retOp(currentStr) != N) { //than its an opeator
      oper = currentStr;
      expStart = ret;//get current placement of operator so we know not at left
      ret++;
      currentStr = *(it + ret);
      continue;
    }
    if (expStart == 0) {//if still ay left
      l += currentStr;
    } else { //at right
      r += currentStr;
    }
    ret++;
    currentStr = *(it + ret);
  }
  ret++;
  operate op = retOp(oper);//gets operator by enum
  double left = helper->getInterpret()->interpret(l)->calculate();
  double right = helper->getInterpret()->interpret(r)->calculate();
  switch (op) { //get condition by operator
    case (SMALLER):this->condition = left < right;
      break;
    case (BIGGER):this->condition = left > right;
      break;
    case (SE):this->condition = left <= right;
      break;
    case (BE):this->condition = left >= right;
      break;
    case (EQ):this->condition = left == right;
      break;
    case (NE):this->condition = left != right;
      break;
    default:cerr << "not valid condition" << endl;
      break;
  }
  return ret;
}

/**
 *
 * @param str of potential operator.
 * @return the operator by its enum kind.
 */
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
  return N;//not an operator
}
/**
 * execute commands in condition.
 * @param it iterator of lexer
 * @return number of steps to jump
 */
int ConditionParser::bracketsCommands(vector<string>::iterator it) {
  string str = *(it);
  int index = 0;
  while (str != "}") {
    Command *c = helper->getCommandMap()[str];
    if (c != nullptr) {
      index += c->execute(it + index);
    } else {
      try {
        if (helper->getInterpret()->isVariable(*(it + index))) { //checks if it is a variable
          c = helper->getManager()->getCommands()["var"];
          index += c->execute(it + index);
        } else { //its a func
          c = helper->getManager()->getCommands()["Func"];
          index += c->execute(it + index);
      }
      }
      catch (const char *e) { //catch if not a valid command or function/variable
        cerr << e << endl;
        throw e;
      }
      catch (exception &e) {
        throw e;
      }
    }
    str = *(it + index);
  }
  index++;
  return index;
}

#endif //SIMULATORPROJECT_COMMANDS_CONDITIONPARSER_H_
