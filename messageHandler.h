//
// Created by mike on 3/21/18.
//
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <unistd.h>
#include <netdb.h>

#ifndef CHAT_MESSAGEHANDLER_H
#define CHAT_MESSAGEHANDLER_H

#define bufsize 1024
#define PORT 1050
#define NOT !

//using namespace std;


class messageHandler
{
public:
    messageHandler();
    ~messageHandler();
    int serverSetup();
    int clientSetup(std::string ipAddress);
    int sendMessage(std::string message);
    std::string receiveMessage();




private:
    //Used for both.
    int portNum;
    int client;
    struct sockaddr_in server_addr;
    bool isServer;//True = server, false = client.
    bool typeAssigned;//Prevents user from running clientSetup then serverSetup.


    //Server stuff.

    socklen_t size;
    int server;

    //Client stuff.

    char *ip;

};


#endif //CHAT_MESSAGEHANDLER_H
