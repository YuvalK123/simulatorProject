
// Created by yuval Kasner on 28/12/19.
//

#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_IFCOMMAND_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_IFCOMMAND_H_
#include "ConditionParser.h"

class IfCommand : public ConditionParser {
 private:
//  int bracketsCommands(vector<string>::iterator it);
 public:
  explicit IfCommand() = default;
  int execute(vector<string>::iterator it) override;
};

int IfCommand::execute(vector<string>::iterator it) {
  int retValue = setCondition(it);
  if (this->condition) {
    retValue += bracketsCommands(it + retValue);
//    for (Command* command : this->commands){
//      retValue += command->execute(it + retValue);
//    }
  } else { //condition doesnt happen
    string str = *(it + retValue);
    while (str != "}") {
      retValue++;
      str = *(it + retValue);
    }
    retValue++;
  }
  return retValue;
}

#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_IFCOMMAND_H_
