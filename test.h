#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/des.h>


#define BUFSIZE 256

int testdes()
{
    DES_cblock key;
    /**//* DES_random_key(&key); */ /**//* generate a random key */
    DES_string_to_key("pass", &key);

    DES_key_schedule schedule;
    DES_set_key_checked(&key, &schedule);
    const_DES_cblock input = "hehehe";
    DES_cblock output;

    printf("cleartext:%s ", input);
    DES_ecb_encrypt(&input, &output, &schedule, DES_ENCRYPT);
    printf("Encrypted! ");

    printf("ciphertext:");
    int i;
    for (i = 0; i < sizeof(input); i++)
        printf("%02x", output[i]);
    printf(" ");

    DES_ecb_encrypt(&output, &input, &schedule, DES_DECRYPT);
    printf("Decrypted! ");
    printf("cleartext:%s ", input);

    return 0;
}
