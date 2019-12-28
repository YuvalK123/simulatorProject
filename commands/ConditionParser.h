//
// Created by yuval Kasner on 20/12/19.
//

#ifndef SIMULATORPROJECT_COMMANDS_CONDITIONPARSER_H_
#define SIMULATORPROJECT_COMMANDS_CONDITIONPARSER_H_
#include "Command.h"
class ConditionParser : public Command {
 private:
  string getArithmetic(string left, string right, const char *arithmetic);
 protected:
  bool condition = false;
  vector<Command *> commands;
 public:
  ConditionParser() = default;
  int execute(vector<string>::iterator it) override = 0;
  void initiateCond(vector<const char *> vec, int index);
};



#endif //SIMULATORPROJECT_COMMANDS_CONDITIONPARSER_H_
