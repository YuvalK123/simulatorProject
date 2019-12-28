//
// Created by yuval Kasner on 26/12/19.
//

#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SIMMANAGER_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SIMMANAGER_H_
#include "commands/Command.h"
#include "unordered_map"
#include "iostream"
using namespace std;
class SimManager {
  //send iterator
 private:
  unordered_map<string, Command *> vars;
  vector<string> lex;
  unordered_map<string, int> id2Index;
  vector<double> varVals;

  int index;

 public:
  SimManager();
  void initVarss();
  void lexer(ifstream &file);
  void parser();
  static vector<string> split(string str, string token);
  void assignValByVec(vector<string> vals);
  int getIndex();
  Command *getVar(const string &var);
  string getLex(int ind);
};

#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SIMMANAGER_H_
