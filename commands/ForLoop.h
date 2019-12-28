//
// Created by yuval Kasner on 28/12/19.
//

#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_FORLOOP_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_FORLOOP_H_

#include "LoopCommand.h"
#include "DefineVarCommand.h"
#include <vector>
class ForLoop : LoopCommand {
 private:
  //funcs
  void init();
  void operation();
 public:
  ForLoop() = default;
  int execute(vector<string>::iterator it) override;
};

#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_FORLOOP_H_
