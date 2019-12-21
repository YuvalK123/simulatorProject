//
// Created by yuval Kasner on 20/12/19.
//

#include "Command.h"
class ConnectCommand : Command {
 public:
  int execute() override;
};

int ConnectCommand::execute() {
  return 0;
}