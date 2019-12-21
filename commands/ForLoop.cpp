//
// Created by yuval Kasner on 20/12/19.
//
#include "LoopCommand.cpp"
#include "DefineVarCommand.cpp"
#include <vector>
using namespace std;
class ForLoop : LoopCommand {
 private:

  ForLoop() : LoopCommand(false) {}
  //funcs
  void init();
  void operation();
 public:
  int execute() override;
};
int ForLoop::execute() {
  return 0;
}
void ForLoop::operation() {

}
void ForLoop::init() {

}
