//
// Created by yuval Kasner on 20/12/19.
//

#include "Command.h"
class FuncCommand : Command {
 public:
  int execute() override;
};
int FuncCommand::execute() {
  return 0;
}
