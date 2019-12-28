//
// Created by yuval Kasner on 28/12/19.
//

#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_DEFINEVARCOMMAND_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_DEFINEVARCOMMAND_H_

#include "Command.h"
#include "iostream"
class DefineVarCommand : Command {
  enum side { None, INPUTVAL, OUTPUTVAL };
  double value;
  const char *ID = "";
  const char *sim;
  side arrow = None;
 public:
  int execute(vector<string>::iterator it) override;
  DefineVarCommand();
//  DefineVarCommand(int val, const char* var, char side);
  DefineVarCommand &operator=(int);
  void simVar(const char *side, const char *var);
};

#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_COMMANDS_DEFINEVARCOMMAND_H_
