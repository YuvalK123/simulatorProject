//
// Created by yuval Kasner on 21/12/19.
//

#ifndef SIMULATORPROJECT_COMMANDS_LOOPCOMMAND_H_
#define SIMULATORPROJECT_COMMANDS_LOOPCOMMAND_H_
#include "ConditionParser.h"
class LoopCommand : public ConditionParser {

 public:
  int execute(vector<string>::iterator it) override;
  LoopCommand();
};
#endif //SIMULATORPROJECT_COMMANDS_LOOPCOMMAND_H_
