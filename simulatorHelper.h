////
//// Created by yuval Kasner on 29/12/19.
////
//
#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SIMULATORHELPER_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SIMULATORHELPER_H_
//

#include <iostream>
#include "expression.h"
#include "SimManager.h"

class SimulatorHelper;
static SimulatorHelper *helper;

class SimulatorHelper {
 private:
  //fields
  SimManager *simManager;
  Interpreter *interpret;

 public:
  explicit SimulatorHelper(unordered_map<string, Command *> commands);
  unordered_map<string, Command *> getCommandMap() { return this->simManager->getCommands(); }
  Interpreter *getInterpret() { return this->interpret; }
  SimManager *getManager() { return this->simManager; }
};
//
SimulatorHelper::SimulatorHelper(unordered_map<string, Command *> commands) {
  this->simManager = new SimManager(commands);
  this->interpret = new Interpreter();
}

#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SIMULATORHELPER_H_
