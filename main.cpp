//
// Created by yuval Kasner on 26/12/19.
//
#include "ostream"
#include "chrono"
#include "thread"
#include "Server.h"
#include "commands/DefineVarCommand.h"
#include "commands/OpenServerCommand.h"
#include "commands/ConnectCommand.h"
#include "commands/IfCommand.h"
#include "commands/LoopCommand.h"
#include "commands/Sleep.h"
#include "commands/Print.h"
#include "commands/ForLoop.h"
#include "simulatorHelper.h"
unordered_map<string, Command *> setCommands();

int main(int argc, const char *argv[]) {
  helper = new SimulatorHelper(setCommands());
  helper->getManager()->initVarss();
  ifstream codeFile;
  codeFile.open(argv[1]);
  if (!codeFile.is_open()) {
    cerr << "failed to open from main" << endl;
    return -1;
  }
//  cout << "serv" << endl;
//  Server serv((helper->getManager()));
//  cout<<serv.execute(5400);
//  std::this_thread::sleep_for(std::chrono::seconds(30));
  helper->getManager()->lexer(codeFile);
  helper->getManager()->parser();
  codeFile.close();
}
unordered_map<string, Command *> setCommands() {
  unordered_map<string, Command *> commandMap;
  commandMap.insert(make_pair("openDataServer", new OpenServerCommand()));
  commandMap.insert(make_pair("connectControlClient", new ConnectCommand()));
  commandMap.insert(make_pair("var", new DefineVarCommand()));
  commandMap.insert(make_pair("if", new IfCommand()));
  commandMap.insert(make_pair("while", new LoopCommand()));
  commandMap.insert(make_pair("for", new ForLoop()));
  commandMap.insert(make_pair("Print", new Print()));
  commandMap.insert(make_pair("Sleep", new Sleep()));
  return commandMap;
}