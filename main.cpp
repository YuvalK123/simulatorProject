//
// Created by yuval Kasner on 26/12/19.
//
#include "ostream"
#include "Server.h"
#include "DefineVarCommand.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "IfCommand.h"
#include "LoopCommand.h"
#include "Sleep.h"
#include "Print.h"
#include "FuncCommand.h"

unordered_map<string, Command *> setCommands();

int main(int argc, const char *argv[]) {
  helper = new SimulatorHelper(setCommands());
  helper->getManager()->initNodes();
  ifstream codeFile;
  codeFile.open(argv[argc-1]);
  if (!codeFile.is_open()) {
    cerr << "failed to open from main" << endl;
    return -1;
  }
  try {
    vector<string> code = helper->getManager()->lexer(codeFile);
    helper->parser(code);
    codeFile.close();
  }
  catch (char const *e) {
    cerr << e << endl;
  }
}
unordered_map<string, Command *> setCommands() {
  unordered_map<string, Command *> commandMap;
  commandMap.insert(make_pair("openDataServer", new OpenServerCommand()));
  commandMap.insert(make_pair("connectControlClient", new ConnectCommand()));
  commandMap.insert(make_pair("var", new DefineVarCommand()));
  commandMap.insert(make_pair("if", new IfCommand()));
  commandMap.insert(make_pair("while", new LoopCommand()));
  commandMap.insert(make_pair("Print", new Print()));
  commandMap.insert(make_pair("Sleep", new Sleep()));
  commandMap.insert(make_pair("Func", new FuncCommand()));
  return commandMap;
}