//
// Created by yuval Kasner on 20/12/19.
//

#ifndef SIMULATORPROJECT_COMMANDS_CONDITIONPARSER_H_
#define SIMULATORPROJECT_COMMANDS_CONDITIONPARSER_H_
#include "Command.h"
class ConditionParser : Command {
 private:
  bool condition;
 public:
  explicit ConditionParser(bool cond);
  int execute() override = 0;
};
ConditionParser::ConditionParser(bool cond) {
  this->condition = cond;
}
#endif //SIMULATORPROJECT_COMMANDS_CONDITIONPARSER_H_
