//
//  Message Handler: Sets up TCP for server/client. Then allows to send a
//                   message and receive a message
//  03/22/18
//
#include "messageHandler.h"

messageHandler::messageHandler()
{
    typeAssigned = false;//Turns true in setup server/client.
}

messageHandler::~messageHandler()
{
    if(isServer)
    {
        close(server);
    }
    std::cout << "\nConnection terminated\n";
    close(client);
}



//****************************************************************************
//  Sends a message: Checks if the class is a server or a client then sends
//                   the message.
//                   NOTE: Only change incorrect logic/syntax.
//                         Do not add new features to function.
//
//  TODO check that message isn't larger than bufsize, otherwise return -1.
//****************************************************************************
int messageHandler::sendMessage (std::string message)
{
    char buffer[bufsize];
    //Copy message to buffer.
    strcpy(buffer, message.c_str());

    //This sends the message depending on if it's the server or client.
    if(isServer)//Server send message code
    {
        send(server, buffer, bufsize, 0);
    }
    else if(NOT isServer)//Client send message code
    {
        send(client, buffer, bufsize, 0);
    }
    else
    {
        std::cout<<"Invalid message handler, Neither server nor client.\n"
            << "program needs to terminate\n";
        return -1;
    }
    return 1;
}

//****************************************************************************
//Receive message: Checks if it's the server or client.
//                 NOTE: Only change incorrect logic/syntax. Do not add
//                       new features to function.
//
//TODO check if received message was successful (Optional).
//****************************************************************************
std::string messageHandler::receiveMessage ()
{
    char buffer[bufsize];

    //This sends the message depending on if it's the server or client.
    if(isServer)//Server send message code
    {
        recv(server, buffer, bufsize, 0);
    }
    else if(NOT isServer)//Client send message code
    {
        recv(client, buffer, bufsize, 0);
    }
    else
    {
        std::cout<<"Invalid message handler, Neither server nor client.\n"
            << "program needs to terminate\n";
        return "None";
    }

    std::string message = buffer;
    return message;
}



//****************************************************************************
//****************************************************************************
//
//  Server Code
//
//****************************************************************************
//****************************************************************************

//Sets up the server variables. Port can be changed from define in .h
int messageHandler::serverSetup()
{
    //If the type has already been assigned return with error
    if(typeAssigned)
    {
        std::cout<<"ERROR: type is already assigned\n";
        return -1;
    }
    typeAssigned = true;

    char buffer[bufsize];
    isServer = true;
    portNum = PORT;

    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0)
    {
        std::cout << "\nError establishing socket" << std::endl;
        return -1;
    }
    std::cout << "Socket server created\n";

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);

    if ((bind(client, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0)
    {
        std::cout << "Error binding connection. Port may be used" << std::endl;
        return -1;
    }

    size = sizeof(server_addr);
    std::cout << "Looking for client\n";

    listen(client, 1);

    server = accept(client,(struct sockaddr *)&server_addr,&size);
    if (server < 0)
        std::cout << " Error on accepting" << std::endl;

    strcpy(buffer, "Server connected!\n*********************");
    std::cout<<"\nInit send: " << buffer;
    send(server, buffer, bufsize, 0);
    return 1;
}

//****************************************************************************
//****************************************************************************
//
//  Client Code
//
//****************************************************************************
//****************************************************************************

//Sets up the client variables. Port can be changed from #define in .h
int messageHandler::clientSetup(std::string ipAddress)
{
    //If the type has already been assigned return with error
    if(typeAssigned)
    {
        std::cout<<"ERROR: type is already assigned\n";
        return -1;
    }
    typeAssigned = true;

    char buffer[bufsize];
    isServer = false;
    portNum = PORT;

    //https://stackoverflow.com/questions/7352099/stdstring-to-char TODO maybe change this to a better way (may segfault)
    ip = new char[ipAddress.length() + 1];
    strcpy(ip, ipAddress.c_str());


    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0)
    {
        std::cout << "\nError establishing socket" << std::endl;
        return -1;
    }
    std::cout << "Socket client created" << std::endl;

    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);

    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        std::cout << "Connection to the server FAILED " << portNum << std::endl;
        return -1;
    }
    recv(client, buffer, bufsize, 0);
    std::cout << "Init Recv: " << buffer;
    return 1;
}








