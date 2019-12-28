//
// Created by yuval Kasner on 25/12/19.
//
#include "vector"
#include "string"
#include <unordered_map>
#include "commands/Command.h"
using namespace std;
class Observer {
 private:
  int *index;
  unordered_map<string, Command *> updateFromSim;
  unordered_map<string, Command *> updateToSim;

 public:
  void notify(string sim, int value);
//  Observer(int* ind,unordered_map<string,Command*> newMap);

};
//Observer::Observer(int *ind, unordered_map<string, Command *> newMap) {
//  this->index = ind;
//  this->vars = newMap;
//}
