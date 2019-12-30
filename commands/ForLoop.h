//
// Created by yuval Kasner on 28/12/19.
//

#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_FORLOOP_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_FORLOOP_H_

#include "LoopCommand.h"
#include <vector>
class ForLoop : public LoopCommand {
 private:
  //funcs
  void init();
  void operation();
 public:
  explicit ForLoop() = default;
  int execute(vector<string>::iterator it) override;
};
int ForLoop::execute(vector<string>::iterator it) {
  init();
//  while (condition) {
//    LoopCommand::execute(vec,index);
//    operation();
//  }
  return 0;
}
void ForLoop::operation() {
  this->condition = false;
}
void ForLoop::init() {

}
#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_FORLOOP_H_
