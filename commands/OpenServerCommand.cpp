//
// Created by yuval Kasner on 20/12/19.
//

#include "Command.h"
#include "../server.cpp"
class OpenServerCommand : Command {
 private:
  Server server;
 public:
  int execute() override;
};

int OpenServerCommand::execute() {
  return server.execute();
}

