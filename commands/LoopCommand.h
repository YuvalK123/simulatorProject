//
// Created by yuval Kasner on 21/12/19.
//

#ifndef SIMULATORPROJECT_COMMANDS_LOOPCOMMAND_H_
#define SIMULATORPROJECT_COMMANDS_LOOPCOMMAND_H_
#include "ConditionParser.h"
class LoopCommand : public ConditionParser {

 public:
  int execute(vector<string>::iterator it) override;
  explicit LoopCommand() = default;
};

int LoopCommand::execute(vector<string>::iterator it) {
  int retValue = 0, tmp = setCondition(it);
  if (!this->condition) { //condition doesnt happen
    retValue = tmp;
    string str = *(it + retValue);
    while (str != "}") {
      retValue++;
      str = *(it + retValue);
    }
    retValue++;
  }
  while (this->condition) {
    retValue = bracketsCommands(it + tmp);
    setCondition(it);
  }
  retValue += tmp;

  return retValue;
}


#endif //SIMULATORPROJECT_COMMANDS_LOOPCOMMAND_H_
