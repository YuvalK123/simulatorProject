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

using namespace std;

class Client {
 private:
  int client_socket;
 public:
  Client() = default;
  inline int execute(const char *ip, int port);
  inline void sendMsg(const string &msgToSend);
  ~Client() { close(this->client_socket); }
};
/**
 *
 * @param ip to connect to
 * @param port to connect to
 * @return 0 if succeded. else: minus number
 */
int Client::execute(const char *ip, int port) {
  //create socket
  this->client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    //error
    std::cerr << "Could not create a socket" << std::endl;
    return -1;
  }

  sockaddr_in address; //in means IP4
  address.sin_family = AF_INET;//IP4
  address.sin_addr.s_addr = inet_addr(ip);  //the localhost address
  address.sin_port = htons(port);
  //convert our number (both port & localhost) to a number that the network understands.

  // Requesting a connection with the server on local host with port
  int is_connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
  if (is_connect == -1) {
    std::cerr << "Could not connect to host server" << std::endl;
    return -2;
  }
  return 0;
}
/**
 *
 * @param msgToSend to simulator
 */
void Client::sendMsg(const string &msgToSend) {
  string msg = msgToSend + "\r\n";
  int is_sent = send(this->client_socket, msg.c_str(), strlen(msg.c_str()), 0);
  if (is_sent == -1) {
    cerr << "Error sending message" << std::endl;
  }
}

#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_CLIENT_H_
