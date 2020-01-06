//
// Created by yuval Kasner on 20/12/19.
//

#ifndef SIMULATORPROJECT_COMMANDS_COMMAND_H_
#define SIMULATORPROJECT_COMMANDS_COMMAND_H_
#include "vector"
#include "string"

using namespace std;

class Command {
 public:
  virtual int execute(vector<string>::iterator it) = 0;
  virtual ~Command() {}
};

#endif //SIMULATORPROJECT_COMMANDS_COMMAND_H_
