//Encryption/Decryption
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <openssl/des.h>
#include <vector>
//Password hash
#include <openssl/sha.h>
#include <sstream>
#include<iomanip>
#define MAX_PASSWORD_LENGTH 7

using namespace std;

std::string encrypt_message(std::string plaintext, const char *password) {
    int i = 0, n;                                                            //Loop variable Declaration
    DES_cblock key, output;                                                  //Stores DES Key And Output block
    DES_key_schedule schedule{};                                             //Scheduler for DES
    string res;                                                              //Holds the results from one round
    std::vector<char> ve;                                                    //A vector of chars to hold
    for (i = 0; i < plaintext.length() / 7 + 1; ++i) {                       //Through the message 8 Bytes/iteration
        std::string message =                                                //Holds the substring of the plaintext
                plaintext.substr(static_cast<unsigned long>(i * 7), 7);      //Start at i*7 and take then next 7 chars
        DES_string_to_key(password, &key);                                   //Turn password into 56 bit key
        DES_set_key_checked(&key, &schedule);                                //Check key
        n = static_cast<int>(message.length());                              //Set n to length of substring
        DES_cblock input[n + 1];                                             //Initialize block to n+1 (usually 8 bytes)
        strcpy(reinterpret_cast<char *>(input), message.c_str());            //Copy the message into the input block
        DES_ecb_encrypt(                                                     //DES encrypt using openssl library
                reinterpret_cast<const_DES_cblock *>(&input),                //Input block
                &output,                                                     //Output block
                &schedule,                                                   //DES scheduler
                DES_ENCRYPT                                                  //Tells feistel cipher to run encryption
        );
        res = {reinterpret_cast<char *>(output)};                            //Stores round result into string
        std::copy(res.begin(), res.end(), std::back_inserter(ve));           //Copy string to vector
        ve.push_back(' ');                                                  //Push back null terminating char
    }                                                                        //END LOOP
    ve.push_back('\0');
    std::string str(ve.begin(), ve.end());                                   //Turn vector into string for sending
    return str;                                                              //Return Ciphertext
}

std::string decrypt_message(std::string ciphertext, const char *password) {
    int i = 0, n;                                                            //Loop variable Declaration
    DES_cblock key, output;                                                  //Stores DES Key And Output block
    DES_key_schedule schedule{};                                             //Scheduler for DES
    string res;                                                              //Holds the results from one round
    std::vector<char> ve;                                                    //A vector of chars to hold
    for (i = 0; i < ciphertext.length() / 18; ++i) {                         //Through the message 8 Bytes/iteration
        std::string message = ciphertext.substr(                             //Holds the substring of the cipher
                static_cast<unsigned long>(i * 18),                          //Start at i*18 and take then next 18 chars
                18);
        DES_string_to_key(password, &key);                                   //Turn password into 56 bit key
        DES_set_key_checked(&key, &schedule);                                //Check key
        n = static_cast<int>(message.length());                              //Set n to length of substring
        DES_cblock input[n + 1];                                             //Initialize block to n+1 (usually 18 byte)
        strcpy(reinterpret_cast<char *>(input), message.c_str());            //Copy the message into the input block
        DES_ecb_encrypt(                                                     //DES decrypt using openssl library
                reinterpret_cast<const_DES_cblock *>(&input),                //Input block
                &output,                                                     //Output block
                &schedule,                                                   //DES scheduler
                DES_DECRYPT                                                  //Tells feistel cipher to run decryption
        );
        res = {reinterpret_cast<char *>(output)};                            //Stores round result into string
        std::copy(res.begin(), res.end(), std::back_inserter(ve));           //Copy string to vector
    }                                                                        //END LOOP
    std::string str(ve.begin(), ve.end());                                   //Turn vector into string for sending
    return str;
}

std::string passwordRegen(string &password){
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);
    std::stringstream temp;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        temp << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    cout<<"\nPassChange = "<<temp.str().substr(0, MAX_PASSWORD_LENGTH);
    return temp.str().substr(0, MAX_PASSWORD_LENGTH);
}

int test() {
    //NOTE: Password Must Be 1-7 Characters for DES
    const char *password = "123";
    string ciphertext = "";
    string plaintext = "";
    string message = "asdlf kjasd;f lkjasd;f lkjasdf";
    std::cout << "MESSAGE: " + message << endl;
    std::cout << "ENCRYPTING..." << endl;
    ciphertext = encrypt_message(message, password);
    std::cout << "SENDING MESSAGE SIMULATION" << endl;
    std::cout << "DECRYPTING..." << endl;
    plaintext = decrypt_message(ciphertext, password);
    std::cout << "RESULTS: " + plaintext;
    return 0;
}


