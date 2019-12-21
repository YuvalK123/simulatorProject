//
// Created by yuval Kasner on 20/12/19.
//
#include "ConditionParser.h"
class IfCommand : ConditionParser {
 public:
  int execute() override;
};

int IfCommand::execute() {
  return 0;
}