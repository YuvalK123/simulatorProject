//
// Created by yuval Kasner on 29/12/19.
//

#ifndef SIMULATORPROJECT_CPLUS_PROJECTS_SIMULATORPROJECT_COMMANDS_PRINT_H_
#define SIMULATORPROJECT_CPLUS_PROJECTS_SIMULATORPROJECT_COMMANDS_PRINT_H_

#include "Command.h"
class Print : public Command {
 public:
  explicit Print() = default;
  int execute(vector<string>::iterator it) override;
};

int Print::execute(vector<string>::iterator it) {
  string content = *(it + 1);
  if (content.c_str()[0] == '"') {
    content.erase(std::remove(content.begin(), content.end(), '"'), content.end());
    cout << content << endl;
  } else {
    //    double value = helper->getInterpret()->getVars()[content]->calculate();
    double value = helper->getInterpret()->interpret(content)->calculate();
    cout << value << endl;
  }
  return 2;
}

#endif //SIMULATORPROJECT_CPLUS_PROJECTS_SIMULATORPROJECT_COMMANDS_PRINT_H_
