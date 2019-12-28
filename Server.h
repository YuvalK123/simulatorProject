//
// Created by yuval Kasner on 27/12/19.
//

#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SERVER_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SERVER_H_

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>
#include <netinet/in.h>
#include "commands/Command.h"
#include "thread"
#include "SimManager.h"
using namespace std;
static bool isDone = false;
static SimManager *manager;
class Server {
 private:

 public:
  explicit Server(SimManager *manage) { manager = manage; };
  ~Server() { isDone = true; }
  int execute(int port);
  static void recvMsg(int clientSocket, int bufferSize);
};

#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SERVER_H_
