//
// Created by yuval Kasner on 27/12/19.
//

#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_OPENSERVERCOMMAND_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_OPENSERVERCOMMAND_H_

#include "Command.h"
#include "Server.h"
class OpenServerCommand : public Command {
 private:
  Server server;
 public:
  explicit OpenServerCommand() = default;
  int execute(vector<string>::iterator it) override;
};

int OpenServerCommand::execute(vector<string>::iterator it) {
  int port, retValue = 2;
  port = (int) helper->getInterpret()->interpret(*(it + 1))->calculate();//calculate port
  int trys = server.execute(port);//trys to open server
  while (trys < 0) {//while fails to open server - try
    trys = server.execute(port);
  }
  return retValue;

}

#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_OPENSERVERCOMMAND_H_
