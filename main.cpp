//
// Created by yuval Kasner on 26/12/19.
//
#include "SimManager.h"
#include "ostream"
#include <fstream>
#include "chrono"
#include "thread"
#include "Server.h"
int main(int argc, const char *argv[]) {
//  string fileName = argv[1];
  SimManager sim;
//  sim.initVarss();
  ifstream codeFile;
  codeFile.open("/Users/yuvalkasner/Documents/c++_projects/simulatorProject/fly.txt");
  if (!codeFile.is_open()) {
    cerr << "failed to open from main" << endl;
    return -1;
  }
  cout << "serv" << endl;
  Server serv(&sim);
//  cout<<serv.execute(5400);
//  std::this_thread::sleep_for(std::chrono::seconds(30));
  sim.lexer(codeFile);
  sim.parser();
  codeFile.close();
}