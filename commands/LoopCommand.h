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
  cout << "next after is " + *it << endl;
  bool cond = false;
  while (this->condition) {
    cond = true;
    retValue = bracketsCommands(it + tmp);
    setCondition(it);
  }
  retValue += tmp;
  if (!cond) { //condition doesnt happen
    cout << "not conds" << endl;
    string str = *(it + retValue);
    while (str != "}") {
      retValue++;
      str = *(it + retValue);
    }
    retValue++;
  }
  return retValue;
}


#endif //SIMULATORPROJECT_COMMANDS_LOOPCOMMAND_H_
