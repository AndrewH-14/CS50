// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 675;

// Hash table
node *table[N];

//number of words in the dictionary
int numWords = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int valHash = hash(word);
    //printf("%i\n", valHash);
    if (table[valHash] == NULL)
    {
        return false;
    }
    for (node *cur = table[valHash]; cur != NULL; cur = cur->next)
    {
        if (strcasecmp(word, cur->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int num = 0;
    // char c = tolower(word[0]);
    // num = c - 97;

    char one = tolower(word[0]);
    char two = 97;
    if (word[1] != '\0')
    {
        two = tolower(word[1]);
    }

    int firstLet = (one - 97) % 26;
    int secondLet = two - 97;

    num = (firstLet * 26) + secondLet;

    return num;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //opens file and checks to see if the file can open
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char curWord[LENGTH + 1];
    fscanf(file, "%s", curWord);
    while (!feof(file))
    {
        node *n = malloc(sizeof(node));
        strcpy(n->word, curWord);
        n->next = NULL;
        if (n == NULL)
        {
            return false;
        }
        numWords++;

        for (int i = 0; i < N; i++)
        {
            if (i == hash(curWord))
            {
                if (table[i] == NULL)
                {
                    table[i] = n;
                }
                else
                {
                    node *head = table[i];
                    n->next = head;
                    table[i] = n;
                }
                break;
            }
        }
        fscanf(file, "%s", curWord);
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{

    return numWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cur = table[i];
        node *tmp = NULL;
        while (cur != NULL)
        {
            tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    return true;
}
