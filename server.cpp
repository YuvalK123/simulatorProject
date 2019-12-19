#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>
#include <netinet/in.h>

#define PORT 5400
#define BUFFER 1024
using namespace std;
int main(int argc, char const *argv[]) {
  while (true) {
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1) {
      cerr << "cant create a socket" << endl;
      return -1;
    }
    //bind
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    inet_pton(AF_INET,"0.0.0.0",&address.sin_addr);
    if (bind(listening, (const struct sockaddr *) &address, (socklen_t) sizeof(address)) == -1) {
      cerr << "error binding";
      return -2;
    }
    //mark the socket
    if (listen(listening, 1) == -1) {
      cerr << "cant mark";
      return -3;
    }
    //accept a call
    sockaddr_in client{};
    socklen_t clientSize = sizeof(client);
    char host[NI_MAXHOST];
    char svc[NI_MAXHOST];
    int clientSocket = accept(listening, (sockaddr *) &client, &clientSize);
    if (clientSocket == -1) {
      cerr << "problem with client conn";
      return -4;
    }
    //close the listening socket
    close(listening);
    memset(host,0,NI_MAXHOST);
    memset(svc,0,NI_MAXSERV);
    int result = getnameinfo((sockaddr*)&clientSocket, sizeof(clientSocket),host,NI_MAXHOST,svc,NI_MAXSERV,0);
    if(result){
      cout<<host<< "connected on service"<<endl;
    } else{
      inet_ntop(AF_INET,&client.sin_addr,host,NI_MAXHOST);
      cout<<host<<"connected on"<<ntohs(client.sin_port)<<endl;
    }

    //while recieving - disp msg
    char buff[BUFFER];
    while (true){
      //clear buffer
      memset(buff,0,BUFFER);
      //wait for msg
      int byteRecv = recv(clientSocket,buff,BUFFER,0);
      if (byteRecv == -1){
        cerr<<"connection issue"<<endl;
        break;
      }
      if(byteRecv == 0){
        cout<<"client disconnected"<<endl;
        break;
      }
      //disp msg
      cout<<"recieved"<<string(buff,0,byteRecv)<<endl;
      //resend msg
      send(clientSocket,buff,byteRecv+1,0);
    }
    //close
    close(clientSocket);
  }
}
