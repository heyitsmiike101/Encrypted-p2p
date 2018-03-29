#include <iostream>
#include "messageHandler.h"
#include "messageEncryption.h"
//Processes
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMKEY ((key_t) 1497)

typedef struct
{
    bool quit;//Receive process will quit when process->quit = true
    bool changPass;//This will be shared between the processes so
                   // that the password can stay the same without being a global variable.
} shared_mem;
shared_mem *process;

int send(messageHandler &mailman, string password);
void recv(messageHandler &mailman, string password);


using namespace std;

int main() {

    messageHandler mailman;
    string answer, password;
    DES_cblock key, output;
    //Setup The Key for DES using password
    cout << "Please Enter The Password" << endl;
    getline(cin, password);
    cout << "Messaging System CLI: Please Enter... \n1 for server \n2 for client\n";
    getline(cin, answer);

    if (answer == "1") {
        cout << "\n*********************\n";
        cout << "Server Selected";
        cout << "\n*********************\n";
        int check = mailman.serverSetup();
        if (check < 0) {
            exit(1);
        }
    } else {
        cout << "\n*********************\n";
        cout << "client selected";
        cout << "\n*********************\n";

        int check = mailman.clientSetup("127.0.0.1");
        if (check < 0) {
            exit(1);
        }

        cout << endl << "Send the first message: ";
        send(mailman, password);
    }

    //DEVELOP PROCESSES
    int pid1;//Recv process.
    int shmid;
    char *shmadd;
    shmadd = (char *)0;


    if((shmid = shmget(SHMKEY, sizeof(int), IPC_CREAT|0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }
    if((process = (shared_mem*) shmat(shmid, shmadd, 0)) == (shared_mem *) -1)
    {
        perror("shmat");
        exit(0);
    }
    process->quit = false;

    //Fork to keep receiving messages until send message returns -1
    pid1 = fork();
    if(pid1 == 0)
    {
        while(!process->quit)
        {
            recv(mailman, password);
        }
        exit(0);
    }

    while(!process->quit)
    {
        int sendCode = send(mailman, password);
        if(sendCode == -1)
        {
           process->quit = true;
        }
        if(sendCode == -2)
        {
            //TODO change password...
        }

    }

    shmdt(process);
    shmctl(shmid, IPC_RMID, NULL);
    cout<<"Program Terminating";
    return 0;
}

int send(messageHandler &mailman, string password)
{
    string message;
    getline(cin, message);
    if(message == "QUIT")
    {
        return -1;//To quit process.
    }
    if(message == "CHANGEPASSWORD")
    {
        string cipher = encrypt_message(message, password.c_str());
        mailman.sendMessage(cipher);
        return -2;//Change password for both processes.
    }

    string cipher = encrypt_message(message, password.c_str());
    mailman.sendMessage(cipher);
    return 1;
}

void recv(messageHandler &mailman, string password)
{
    string recv = mailman.receiveMessage()+'\0'; //DON'T REMOVE
    string plaintext= decrypt_message(recv, password.c_str());
    cout << "Recv: "+ plaintext << endl;
}