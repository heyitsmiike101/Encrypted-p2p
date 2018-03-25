#include <iostream>
#include "messageHandler.h"
//#include "messageEncryption.h"

using namespace std;

int main() {

    messageHandler mailman;
    string answer, password;
    //Setup The Key for DES using password
    cout << "Please Enter The Password" << endl;
    getline(cin, password);
    mailman.setPassword(password);
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
        mailman.encryptSend (message);
    }



    cout << "\nTo Quit the chat type: QUIT\n";
    int i = 0;
    while (i < 6) {
        string recv = mailman.encryptRecv ();
        if (recv == "QUIT") {
            exit(1);
        }
        cout << "\nRecv: ";
        cout << recv << endl;

        cout << "\nSend: ";
        string send;
        getline(cin, send);
        //cin.clear();
        if (send == "QUIT") {
            mailman.encryptSend (send);
            exit(1);
        }
        mailman.encryptSend (send);
        i++;

    }
    cout << endl << endl << endl;
    return 0;
}