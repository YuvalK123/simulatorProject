////
//// Created by yuval Kasner on 29/12/19.
////
//
#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SIMULATORHELPER_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SIMULATORHELPER_H_

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
  void parser(vector<string> lex);

};

SimulatorHelper::SimulatorHelper(unordered_map<string, Command *> commands) {
  this->simManager = new SimManager(commands);
  this->interpret = new Interpreter();
}

/**
 *method executes the lexer
 * @param lex to work by.
 */
void SimulatorHelper::parser(vector<string> lex) {
  unsigned int index = 0;
  auto it = (lex).begin();
  while (index < lex.size()) {
    Command *c = nullptr;
    c = this->getManager()->getCommands()[*(it + index)];
    if (c != nullptr) {//its a known command
      index += c->execute(it + index);
    } else {//either a variable or a function
      try {
        if (this->getInterpret()->isVariable(*(it + index))) {//checks if it is a variable
          c = this->simManager->getCommands()["var"];
          index += c->execute(it + index);
        } else {
          c = this->simManager->getCommands()["Func"];
          index += c->execute(it + index);
        }
      }
      catch (const char *e) {//catch if not a valid command or function/variable
        cerr << e << endl;
        throw e;
      }
      catch (exception &e) {
        cerr << e.what() << endl;
        throw e.what();
      }
    }
  }
}

#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SIMULATORHELPER_H_
