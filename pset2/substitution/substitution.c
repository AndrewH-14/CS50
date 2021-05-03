#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]) == 0)
            {
                printf("key can only contain alphabetical letters\n");
                return 1;
            }
            for (int j = 0; j < n; j++)
            {
                if ((tolower(argv[1][i]) == tolower(argv[1][j])) && (i != j))
                {
                    printf("key cannot contain duplicate letters\n");
                    return 1;
                }
            }
        }
    }

    string str = get_string("plaintext: ");
    int num = 0;
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (islower(str[i]))
        {
            num = str[i] - 97;
            str[i] = tolower(argv[1][num]);
        }
        else if (isupper(str[i]))
        {
            num = str[i] - 65;
            str[i] = toupper(argv[1][num]);
        }
    }
    printf("ciphertext: %s", str);
    printf("\n");
    return 0;
}