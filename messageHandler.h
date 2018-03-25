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
#include <vector>


#ifndef CHAT_MESSAGEHANDLER_H
#define CHAT_MESSAGEHANDLER_H



#define bufsize 1024
#define PORT 1051
#define NOT !



class messageHandler
{
public:
    messageHandler();
    ~messageHandler();
    int setPassword(std::string password);
    int serverSetup();
    int clientSetup(std::string ipAddress);
    int encryptSend(std::string message);
    std::string encryptRecv();




private:
    //Used for both.
    //**********Functions**********
    int sendMessage(std::string message);
    std::string receiveMessage();
    //**********Variables**********
    int portNum;
    int client;
    struct sockaddr_in server_addr;
    bool isServer;//True = server, false = client.
    bool typeAssigned;//Prevents user from running clientSetup then serverSetup.
    char *pass;

    //Server stuff.
    socklen_t size;
    int server;

    //Client stuff.
    char *ip;

};


#endif //CHAT_MESSAGEHANDLER_H
