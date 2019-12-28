
// Created by yuval Kasner on 28/12/19.
//

#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_IFCOMMAND_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_IFCOMMAND_H_
#include "ConditionParser.h"

class IfCommand : ConditionParser {
 public:
  IfCommand() = default;
  int execute(vector<string>::iterator it) override;
};

#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_IFCOMMAND_H_
