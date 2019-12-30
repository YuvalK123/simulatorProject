//
// Created by yuval Kasner on 27/12/19.
//

#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_OPENSERVERCOMMAND_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_OPENSERVERCOMMAND_H_

#include "Command.h"
#include "../Server.h"
class OpenServerCommand : public Command {
 private:
  Server server;
//  vector<vars> = #vars = (x,y,w...z)
// update value of var by them pointing/not pointing on vector[var]
 public:
  explicit OpenServerCommand() = default;
  int execute(vector<string>::iterator it) override;
};

int OpenServerCommand::execute(vector<string>::iterator it) {
  int port, retValue = 2;
//  try {
  port = stoi(*(it + 1));
  cout << "port is " << port << endl;
  int trys = server.execute(port);
  while (trys < 0) {
    cout << "smaller" << endl;
    trys = server.execute(port);
  }
//  }
//  catch (runtime_error &e) {
//    cerr<<"runtime err"<<endl;
//    throw "runtime error";
//  }
//  catch (exception &e) {
//    cerr<<"ex err"<<endl;
//    throw "exception";
//  }
  return retValue;

}

#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_OPENSERVERCOMMAND_H_
