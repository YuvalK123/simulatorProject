////
//// Created by yuval Kasner on 26/12/19.
////
//
#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SIMMANAGER_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SIMMANAGER_H_
//
#include <unordered_map>
#include <iostream>
#include <fstream>
#include "vector"
#include <regex>
#include "commands/Command.h"
#include "Client.h"
//


class SimManager {
  //send iterator
 private:
  vector<string> lex;
  unordered_map<string, int> id2InIndex;
  unordered_map<string, int> id2OutIndex;
  vector<double> inVals;
  vector<double> outVals;
  unordered_map<string, Command *> commandMap;
  Client *client;

 public:
  explicit SimManager(unordered_map<string, Command *> command);
  unordered_map<string, Command *> getCommands() { return this->commandMap; }
  void initVarss();
  void lexer(ifstream &file);
  void parser();
  static vector<string> split(string str, const string &token);
  void assignValByVec(const vector<string> &vals);
  vector<double>::iterator getInIndex(string str);
  vector<double>::iterator getOutIndex(string str);
  void sendMsg(const string &msg);
  void setClient(Client *c) { this->client = c; }
};
//


#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SIMMANAGER_H_
