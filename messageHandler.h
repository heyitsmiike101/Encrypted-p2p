//
// Created by mike on 3/21/18.
//
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>

#ifndef CHAT_MESSAGEHANDLER_H
#define CHAT_MESSAGEHANDLER_H
#define NOT !

//Can be changed depending on requirements.
#define bufsize 7168
#define PORT 1056


class messageHandler
{
public:
    //Setup: 1 Required.
    int serverSetup(int t);
    int clientSetup(std::string ipAddress,int timeout);
    //Messaging
    int sendMessage(std::string message);
    std::string receiveMessage();

private:
    //Used for both.
    int portNum;
    int client;
    struct sockaddr_in server_addr;
    bool isServer;
    //Server stuff.
    socklen_t size;
    int server;
    //Client stuff.
    char *ip;
};

#endif //CHAT_MESSAGEHANDLER_H
