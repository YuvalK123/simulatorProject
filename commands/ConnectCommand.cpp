//
// Created by yuval Kasner on 20/12/19.
//

#include "Command.h"
class ConnectCommand : Command {
 public:
  int execute(vector<string>::iterator it) override;
};

int ConnectCommand::execute(vector<string>::iterator it) {
  return 0;
}