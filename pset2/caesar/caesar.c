#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    int key;
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        key = atoi(argv[1]);
        // printf("Success\n");
        //printf("%i\n", key);
    }

    string str = get_string("plaintext: ");
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (key > 26)
        {
            key = key % 26;
        }
        if (isupper(str[i]))
        {
            if ((str[i] + key) < 90)
            {
                str[i] = str[i] + key;
            }
            else
            {
                str[i] = ((str[i] + key) % 90) + 64;
            }
        }
        else if (islower(str[i]))
        {
            if ((str[i] + key) < 122)
            {
                str[i] = str[i] + key;
            }
            else
            {
                str[i] = ((str[i] + key) % 122) + 96;
            }
        }
        //printf("%i\n", str[i]);
    }

    printf("ciphertext: %s\n", str);
    return 0;
}