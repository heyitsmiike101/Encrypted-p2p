//
// Created by mike on 3/21/18.
//
#include "messageHandler.h"



int messageHandler::sendMessage (string message)
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
        cout<<"Invalid message handler, Neither server nor client.\n"
            << "program needs to terminate\n";
        return -1;
    }
    return 1;
}


string messageHandler::receiveMessage ()
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
        cout<<"Invalid message handler, Neither server nor client.\n"
            << "program needs to terminate\n";
        return "None";
    }

    string message = buffer;
    return message;
}








//****************************************************************************
//****************************************************************************
//
//  Server Code
//
//****************************************************************************
//****************************************************************************

int messageHandler::serverSetup()
{
    char buffer[bufsize];
    isServer = true;
    portNum = PORT;

    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0)
    {
        cout << "\nError establishing socket" << endl;
        return -1;
    }
    cout << "Socket server created\n";

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);

    if ((::bind(client, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0)
    {
        cout << "Error binding connection. Port may be used" << endl;
        return -1;
    }

    size = sizeof(server_addr);
    cout << "Looking for client\n";

    listen(client, 1);

    server = accept(client,(struct sockaddr *)&server_addr,&size);
    if (server < 0)
        cout << " Error on accepting" << endl;

    strcpy(buffer, "Server connected!\n*********************");
    cout<<"\nInit send: " << buffer;
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

int messageHandler::clientSetup(string ipAddress)
{
    char buffer[bufsize];
    isServer = false;
    portNum = PORT;

    //https://stackoverflow.com/questions/7352099/stdstring-to-char
    ip = new char[ipAddress.length() + 1];
    strcpy(ip, ipAddress.c_str());


    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0)
    {
        cout << "\nError establishing socket" << endl;
        return -1;
    }
    cout << "Socket client created" << endl;

    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);

    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        cout << "Connection to the server FAILED " << portNum << endl;
        return -1;
    }
    recv(client, buffer, bufsize, 0);
    cout << "Init Recv: " << buffer;
    return 1;
}






