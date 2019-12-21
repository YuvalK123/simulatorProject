//
// Created by yuval Kasner on 20/12/19.
//

#include "ConditionParser.h"
#include "vector"
using namespace std;
class LoopCommand : ConditionParser, Command {
 private:
  vector<Command> commands;
 public:
  int execute() override;
  explicit LoopCommand(bool cond);
};
int LoopCommand::execute() {
  int index = 0;
  for (Command command : commands) {
    index += command.execute();
  }
  return index;
}
LoopCommand::LoopCommand(bool cond) : ConditionParser(cond) {

}
