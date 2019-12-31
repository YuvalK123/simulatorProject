//
// Created by yuval Kasner on 29/12/19.
//

#ifndef SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_CLIENT_H_
#define SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_CLIENT_H_

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "thread"
//static string msgToSend;
//static bool exitSend = false;
using namespace std;

class Client {
 private:
  int client_socket;
 public:
  Client() = default;
  inline int execute(const char *ip, int port);
  inline int sendMsg(const string &msgToSend);
  ~Client() { close(this->client_socket); }
};

int Client::execute(const char *ip, int port) {
  //create socket
  this->client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    //error
    std::cerr << "Could not create a socket" << std::endl;
    return -1;
  }

  //We need to create a sockaddr obj to hold address of server
  sockaddr_in address; //in means IP4
  address.sin_family = AF_INET;//IP4
  address.sin_addr.s_addr = inet_addr(ip);  //the localhost address
  address.sin_port = htons(port);
  //we need to convert our number (both port & localhost)
  // to a number that the network understands.

  // Requesting a connection with the server on local host with port
  int is_connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
  if (is_connect == -1) {
    std::cerr << "Could not connect to host server" << std::endl;
    return -2;
  } else {
    std::cout << "Client is now connected to server" << std::endl;
  }

  return 0;
}
int Client::sendMsg(const string &msgToSend) {
  string msg = msgToSend + "\r\n";
  int is_sent = send(this->client_socket, msg.c_str(), strlen(msg.c_str()), 0);
  if (is_sent == -1) {
    std::cout << "Error sending message" << std::endl;
  } else {
//    std::cout << msg << endl << "message sent to server" << std::endl;
  }
//  char buffer[1024] = {0};
//  int valread = read(client_socket, buffer, 1024);
//  cout << buffer << endl;
  return 1;
}

#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_CLIENT_H_
