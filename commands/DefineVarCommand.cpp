//
// Created by yuval Kasner on 20/12/19.
//
#include "Command.h"
class DefineVarCommand : Command {
 public:
  int execute() override;
};

int DefineVarCommand::execute() {
  return 0;
}