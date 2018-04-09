#include <iostream>
#include "messageHandler.h"
#include "messageEncryption.h"
//Processes
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY ((key_t) 1497)

typedef struct {
    bool quit;//Receive process will quit when process->quit = true
    std::string password;//This is the password used. for send and received. Needs to be
    // shared because of process properties.
} shared_mem;

void send(messageHandler &mailman, string &password, shared_mem *process);

std::string recv(messageHandler &mailman, string &password, shared_mem *process);

using namespace std;

int main() {

    messageHandler *pointer;
    string answer, tempPass;
    //Processes variables
    shared_mem *process = nullptr;
    int pid1;//Recv process is child, send is parent.
    int shmid;
    char *shmadd;
    shmadd = (char *) 0;

    //Setup The Key for DES using password
    cout << "Please Enter The Password" << endl;
    getline(cin, tempPass);
    int result = -1;
    int sc, timeout;
    messageHandler mailman{};
    while (result < 0) {
        sc = rand() % 2;                // sc in the range 0 and 1
        timeout = 1;     // sc in the range 0 and 1
        if (sc == 0) {
            result = mailman.serverSetup(timeout);
        } else {
            result = mailman.clientSetup("172.16.1.187", timeout);
        }
    }

    //Process setup.
    if ((shmid = shmget(SHMKEY, sizeof(int), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((process = (shared_mem *) shmat(shmid, shmadd, 0)) == (shared_mem *) -1) {
        perror("shmat");
        exit(0);
    }
    process->quit = false;
    process->password = passwordRegen(tempPass);


    //Fork to keep receiving messages until send message returns -1
    pid1 = fork();
    if (pid1 == 0) {
        while (!process->quit) {
            recv(mailman, process->password, process);
        }
        exit(0);
    } else {
        while (!process->quit) {
            send(mailman, process->password, process);
        }
    }

    //End of Program.
    shmdt(process);
    shmctl(shmid, IPC_RMID, NULL);
    cout << "\nProgram Terminating\n";
    return 0;
}

void send(messageHandler &mailman, string &password, shared_mem *process) {
    string message;
    getline(cin, message);

    string cipher = encrypt_message(message, password.c_str());
    mailman.sendMessage(cipher);

    if (message == "QUIT") {
        exit(1);
    }
}

std::string recv(messageHandler &mailman, string &password, shared_mem *process) {
    //Receive and decrypt
    string recv = mailman.receiveMessage() + '\0'; //DON'T REMOVE
    string plaintext = decrypt_message(recv, password.c_str());

    //If sender quit, receiver will quit as well.
    if (plaintext == "QUIT") {
        process->quit = true;
        std::cout << "\nOther user Terminated program\n";
        exit(1);
    } else {
        cout << "Recv: " + plaintext << endl;
    }
    return plaintext;
}