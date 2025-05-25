#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{

    // checking if right amount of arguments are given
    if (argc != 2)
    {
        printf("provide 1 key\n");
        return 1;
    }
    int len = strlen(argv[1]);

    // should contain all letters of alphabet
    if (len != 26)
    {
        printf("provide key for all chars\n");
        return 1;
    }

    // should not contain any other symbols than letters
    for (int i = 0; i < len; i++ )
    {
        if (!isalpha(argv[1][i]))
        {
            printf("should contain letters\n");
            return 1;
        }
    }

    // making them all uppercase so we don't have to deal with those later
    for (int i = 0; i < len; i++ )
    {
        argv[1][i] = toupper(argv[1][i]);
    }

    // all keys should be unique
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if ((i != j) && (argv[1][i] == argv[1][j]))
            {
                printf("keys should be unique\n");
                return 1;
            }
        }
    }

    // getting the word that will be ciphered
    string key = get_string("plaintext: ");

    for (int i = 0, keylen = strlen(key); i < keylen; i++)
    {
        if (isalpha(key[i]))
        {
            if (toupper(key[i]) == key[i])
            {
                key[i] = argv[1][key[i] - 65];
            }
            else
            {
                key[i] = tolower(argv[1][toupper(key[i]) - 65]);
            }
        }
    }
    printf("ciphertext: %s\n", key);
    return 0;
}
