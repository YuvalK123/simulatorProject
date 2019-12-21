//
// Created by yuval Kasner on 20/12/19.
//

#ifndef SIMULATORPROJECT_COMMANDS_COMMAND_H_
#define SIMULATORPROJECT_COMMANDS_COMMAND_H_

class Command {
 public:
  virtual int execute() { return 0; }
};

#endif //SIMULATORPROJECT_COMMANDS_COMMAND_H_
