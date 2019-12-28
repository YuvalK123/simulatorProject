//
// Created by yuval Kasner on 27/12/19.
//

#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_OPENSERVERCOMMAND_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_OPENSERVERCOMMAND_H_

#include "Command.h"
#include "../Server.h"
class OpenServerCommand : Command {
 private:
  Server server;
//  vector<vars> = #vars = (x,y,w...z)
// update value of var by them pointing/not pointing on vector[var]
 public:

  int execute(vector<string>::iterator it) override;
};

#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_OPENSERVERCOMMAND_H_
