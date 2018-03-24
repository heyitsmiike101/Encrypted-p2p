#include <iostream>
#include "messageHandler.h"
#include "test.h"

using namespace std;

int main() {
    testdes(); return 0;
    messageHandler mailman;
    cout<<"Hello\n1 = server \n2 = client\n";
    string answer;
    getline(cin, answer);


    if(answer == "1")
    {
        cout<<"\n*********************\n";
        cout<<"Server Selected";
        cout<<"\n*********************\n";
        int check = mailman.serverSetup ();
        if (check < 0)
        {
            exit(1);
        }
    }
    else
    {
        cout<<"\n*********************\n";
        cout<<"client selected";
        cout<<"\n*********************\n";

        int check = mailman.clientSetup ("127.0.0.1");
        if (check < 0)
        {
            exit(1);
        }

        cout<<endl<<"Send the first message: ";
        string message;
        getline(cin, message);
        mailman.sendMessage(message);
    }

    cout<<"\nTo Quit the chat type: QUIT\n";
    int i = 0;
    while (i < 6)
    {

        string recv = mailman.receiveMessage();
        if(recv == "QUIT")
        {
            exit(1);
        }
        cout<<"\nRecv: ";
        cout << recv << endl;

        cout << "\nSend: ";
        string send;
        getline(cin, send);
        //cin.clear();
        if(send == "QUIT")
        {
            mailman.sendMessage (send);
            exit(1);
        }
        mailman.sendMessage (send);
        i++;

    }
    cout<<endl<<endl<<endl;
    return 0;
}