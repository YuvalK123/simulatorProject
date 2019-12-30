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
  int is_sent = send(this->client_socket, "hello", strlen("hello"), 0);
  if (is_sent == -1) {
    std::cout << "Error sending message" << std::endl;
  } else {
    std::cout << "hello" << endl << "message sent to server" << std::endl;
  }

  return 0;
}
int Client::sendMsg(const string &msgToSend) {
  int is_sent = send(this->client_socket, msgToSend.c_str(), strlen(msgToSend.c_str()), 0);
  if (is_sent == -1) {
    std::cout << "Error sending message" << std::endl;
  } else {
    std::cout << msgToSend << endl << "message sent to server" << std::endl;
  }
  char buffer[1024] = {0};
  int valread = read(client_socket, buffer, 1024);
  cout << buffer << endl;
  return 1;
}
//  int listening = socket(AF_INET, SOCK_STREAM, 0);
//  if (listening == -1) {
//    close(listening);
////    cerr << "client can't create a socket " << endl;
//    return -1;
//  }
//  //bind
//  sockaddr_in address;
//  address.sin_family = AF_INET;
//  address.sin_addr.s_addr = INADDR_ANY;
//  address.sin_port = htons(port);
//  inet_pton(AF_INET, "0.0.0.0", &address.sin_addr);
//  if (bind(listening, (const struct sockaddr *) &address, (socklen_t) sizeof(address)) == -1) {
//    close(listening);
////    cerr << "error binding";
//    return -2;
//  }
//  //mark the socket
//  if (listen(listening, 1) == -1) {
//    close(listening);
//
////    cerr << "cant mark";
//    return -3;
//  }
//  //accept a call
//  sockaddr_in client;
//  socklen_t clientSize = sizeof(client);
//  char host[NI_MAXHOST];
//  char svc[NI_MAXHOST];
//  this->clientSocket = accept(listening, (sockaddr *) &client, &clientSize);
//  if (clientSocket == -1) {
//    close(listening);
////    cerr << "problem with client conn";
//    return -4;
//  }
//  //close the listening socket
//  close(listening);
//  memset(host, 0, NI_MAXHOST);
//  memset(svc, 0, NI_MAXSERV);
//  int result = getnameinfo((sockaddr *) &clientSocket, sizeof(clientSocket), host, NI_MAXHOST, svc, NI_MAXSERV, 0);
//  if (result) {
//    cout << host << "connected on service" << endl;
//  } else {
//    inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
//    cout << host << "connected on" << ntohs(client.sin_port) << endl;
//  }
//
//  return 2;
#endif //SIMULATORPROJECT_C__PROJECTS_SIMULATORPROJECT_CLIENT_H_
