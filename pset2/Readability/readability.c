#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    //gets string to examine
    string str = get_string("Text: ");

    //get number of letters, words, and sentences
    int numLetters = 0;
    int numWords = 1;
    int numSent = 0;
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        //if char is lower or uppercase add one to the number of letter
        if (isupper(str[i]) || islower(str[i]))
        {
            numLetters++;
        }
        //if char is a space add one to the number of words
        else if (str[i] == ' ')
        {
            numWords++;
        }
        //if char is a punctuation mark add one to the number of sentences
        else if ((str[i] == '.') || (str[i] == '?') || (str[i] == '!'))
        {
            numSent++;
        }
    }
    //printf("%i %i %i\n", numLetters, numWords, numSent);

    int index = 0;
    float L = 0;
    float S = 0;

    L = ((float)numLetters / numWords) * 100.0;
    S = ((float)numSent / numWords) * 100.0;
    //printf("%f %f\n", L, S);
    index = round((0.0588 * L) - (0.296 * S) - 15.8);
    //printf("%i\n", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    return 0;
}