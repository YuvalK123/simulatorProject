//
// Created by yuval Kasner on 20/12/19.
//

#include "Command.h"
class FuncCommand : Command {
 public:
  int execute(vector<string>::iterator it) override;
};
int FuncCommand::execute(vector<string>::iterator it) {
  return 0;
}
