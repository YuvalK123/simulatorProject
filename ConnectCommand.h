//
// Created by yuval Kasner on 29/12/19.
//

#ifndef SIMULATORPROJECT_CPLUS_PROJECTS_SIMULATORPROJECT_COMMANDS_CONNECTCOMMAND_H_
#define SIMULATORPROJECT_CPLUS_PROJECTS_SIMULATORPROJECT_COMMANDS_CONNECTCOMMAND_H_

#include "Command.h"
#include "SimulatorHelper.h"

class ConnectCommand : public Command {
 public:
  explicit ConnectCommand() = default;
  int execute(vector<string>::iterator it) override;
};

int ConnectCommand::execute(vector<string>::iterator it) {
  int reValue = 3, port;
  string ip = *(it + 1);//get ip
  ip.erase(std::remove(ip.begin(), ip.end(), '"'), ip.end());//remove "" from ip
  try {
    port = (int) helper->getInterpret()->interpret(*(it + 2))->calculate();//get port
  }
  catch (const char *e) {//problem calculating port.
    cerr << e << endl;
    return reValue;
  }
  Client *client = new Client();
  int trys = client->execute(ip.c_str(), port);//trys to connect
  while (trys < 0) { //while not being able to connect
    trys = client->execute(ip.c_str(), port);
  }
  helper->getManager()->setClient(client);//sets client to simulator
  return reValue;
}

#endif //SIMULATORPROJECT_CPLUS_PROJECTS_SIMULATORPROJECT_COMMANDS_CONNECTCOMMAND_H_
