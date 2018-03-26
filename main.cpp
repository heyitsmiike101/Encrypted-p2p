#include <iostream>
#include "messageHandler.h"
#include "messageEncryption.h"

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
        string message;
        getline(cin, message);
        string cipher = encrypt_message(message, "pass");
        mailman.sendMessage(cipher);
    }

    cout << "\nTo Quit the chat type: QUIT\n";
    int i = 0;
    while (i < 6) {
        string recv = mailman.receiveMessage()+'\0'; //DON'T REMOVE
        string plaintext= decrypt_message(recv, "pass");
        if (recv == "QUIT") {//Never the case
            exit(1);
        }
        cout << "\nRecv: ";
        cout << "cipher: " +recv << endl;
        cout << "Plaintext: "+ plaintext << endl;

        cout << "\nSend: ";
        string send;
        getline(cin, send);
        string cipher = encrypt_message(send, "pass");
        cout << "cipher: " +cipher << endl;
        if (send == "QUIT") {//never be the case
            mailman.sendMessage(cipher);
            exit(1);
        }
        mailman.sendMessage(cipher);
        i++;

    }
    cout << endl << endl << endl;
    return 0;
}