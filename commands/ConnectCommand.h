//
// Created by yuval Kasner on 29/12/19.
//

#ifndef SIMULATORPROJECT_CPLUS_PROJECTS_SIMULATORPROJECT_COMMANDS_CONNECTCOMMAND_H_
#define SIMULATORPROJECT_CPLUS_PROJECTS_SIMULATORPROJECT_COMMANDS_CONNECTCOMMAND_H_

#include "Command.h"
#include "../SimulatorHelper.h"

class ConnectCommand : public Command {
 public:
  explicit ConnectCommand() = default;
  int execute(vector<string>::iterator it) override;
};

int ConnectCommand::execute(vector<string>::iterator it) {
  int reValue = 3;
  string ip = *(it + 1);
  ip.erase(std::remove(ip.begin(), ip.end(), '"'), ip.end());
  int port = stoi(*(it + 2));
  Client *client = new Client();
  cout << "ip is " << ip << " port is " << port << endl;
  int trys = client->execute(ip.c_str(), port);
  while (trys < 0) {
    trys = client->execute(ip.c_str(), port);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  helper->getManager()->setClient(client);
  return reValue;
}

#endif //SIMULATORPROJECT_CPLUS_PROJECTS_SIMULATORPROJECT_COMMANDS_CONNECTCOMMAND_H_
