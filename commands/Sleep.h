//
// Created by yuval Kasner on 29/12/19.
//

#ifndef SIMULATORPROJECT_CPLUS_PROJECTS_SIMULATORPROJECT_COMMANDS_SLEEP_H_
#define SIMULATORPROJECT_CPLUS_PROJECTS_SIMULATORPROJECT_COMMANDS_SLEEP_H_

#include "Command.h"
#include "thread"
class Sleep : public Command {
 public:
  explicit Sleep() = default;
  int execute(vector<string>::iterator it) override;
};

int Sleep::execute(vector<string>::iterator it) {
  try {
    int secs = stoi(*(it + 1));
    std::this_thread::sleep_for(std::chrono::milliseconds(secs));
    return 2;
  }
  catch (exception &e) {
    throw e.what();
  }
}

#endif //SIMULATORPROJECT_CPLUS_PROJECTS_SIMULATORPROJECT_COMMANDS_SLEEP_H_