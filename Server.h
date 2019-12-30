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
#include "SimulatorHelper.h"
#include "mutex"

static bool isDone = false;
class Server {
 private:

 public:
  explicit Server() = default;
  ~Server() { isDone = true; }
  int execute(int port);
  static void recvMsg(int clientSocket, int bufferSize);
};

int Server::execute(int port) {
  int bufferSize = 1024;
  int listening = socket(AF_INET, SOCK_STREAM, 0);
  if (listening == -1) {
    close(listening);
//    cerr << "server can't create a socket" << endl;
    return -1;
  }
  //bind
  sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);
  inet_pton(AF_INET, "0.0.0.0", &address.sin_addr);
  if (bind(listening, (const struct sockaddr *) &address, (socklen_t) sizeof(address)) == -1) {
//    cerr << "error binding";
    close(listening);
    return -2;
  }
  //mark the socket
  if (listen(listening, 1) == -1) {
//    cerr << "cant mark";
    close(listening);
    return -3;
  }
  //accept a call
  sockaddr_in client;
  socklen_t clientSize = sizeof(client);
  char host[NI_MAXHOST];
  char svc[NI_MAXHOST];
  int clientSocket = accept(listening, (sockaddr *) &client, &clientSize);
  if (clientSocket == -1) {
    close(listening);
//    cerr << "problem with client conn";
    return -4;
  }
  //close the listening socket
  close(listening);
  memset(host, 0, NI_MAXHOST);
  memset(svc, 0, NI_MAXSERV);
  int result = getnameinfo((sockaddr *) &clientSocket, sizeof(clientSocket), host, NI_MAXHOST, svc, NI_MAXSERV, 0);
  if (result) {
    cout << host << "connected on service" << endl;
  } else {
    inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
    cout << host << "connected on" << ntohs(client.sin_port) << endl;
  }
  thread t1(recvMsg, clientSocket, bufferSize);
  t1.detach();
  //while recieving - disp msg
  cout << "return 2" << endl;
  return 2;
}
void Server::recvMsg(int clientSocket, int bufferSize) {
  char buff[bufferSize];
  cout << "recv" << endl;
  mutex x;
  while (!isDone) {
    const std::lock_guard<std::mutex> lock(x);
    memset(buff, 0, bufferSize);//clear buffer
    //wait for msg
    int byteRecv = recv(clientSocket, buff, bufferSize, 0);
    if (byteRecv == -1) {
      cerr << "connection issue" << endl;
      break;
    }
    if (byteRecv == 0) {
      cout << "client disconnected" << endl;
      break;
    }
    string str = string(buff, 0, byteRecv);
//    cout << "recieved " << str << endl;
    vector<string> vec = helper->getManager()->split(str, ",");
    helper->getManager()->assignValByVec(vec);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }
  //close
  close(clientSocket);
}


#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_SERVER_H_
