#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "movieWatchers.h"

#define MAXLENGTH 50

Person_Node* NameOptions(Person_Node* head);

void MovieOptions(Person_Node* head);

int main(void)
{
    Person_Node* head = NULL;
    head = loadList(head);

    char userInput = ' ';
    printf("\n");

while (userInput != 'q')
    {
        printf("Program Menu\n");
        printf("n - Name Menu\n");
        printf("m - Movie Menu\n");
        printf("q - Quit\n");

        printf("\nChoose an option:\n");
        scanf(" %c", &userInput);
        printf("\n");

        if (userInput == 'n')
        {
            GetNewline();
            head = NameOptions(head);
        }
        else if (userInput == 'm')
        {
            GetNewline();
            MovieOptions(head);
        }
    }
    saveList(head);
    freeAll(head);
    return 0;
}

//outputs options regarding a specific person's movie list
void MovieOptions(Person_Node* head)
{
    char name[MAXLENGTH];
    printf("Enter User Name:\n");
    GetName(name);
    printf("\n");
    Person_Node* userNode = NULL;

    if (head == NULL)
    {
        printf("No names in list\nExiting movie menu...\n\n");
        return;
    }

    for (Person_Node* cur = head; cur != NULL; cur = cur->nextPersonNode)
    {
        if (strcmp(cur->name, name) == 0)
        {
            userNode = cur;
            break;
        }
        else if (cur->nextPersonNode == NULL)
        {
            printf("Person not found\n");
            printf("Exiting movie menu...\n");
            return;
        }
    }

    char userInput = ' ';

    while (userInput != 'q')
    {
        printf("%s's Movie Menu\n", userNode->name);
        printf("a - Add a movie\n");
        printf("r - Remove a movie\n");
        printf("l - List all watched movies\n");
        printf("t - List top movies\n");
        printf("c - Change user\n");
        printf("q - quit\n");

        printf("\nChoose an option:\n");
        scanf(" %c", &userInput);
        printf("\n");

        if (userInput == 'a')
        {
            GetNewline();
            printf("Enter a movie title to add:\n");
            AddMovie(userNode);

            printf("\n");
        }
        else if (userInput == 'r')
        {
            GetNewline();
            RemoveMovie(userNode);
            printf("\n");
        }
        else if (userInput == 'l')
        {
            GetNewline();
            ListAllMovies(userNode);
            printf("\n");
        }
        else if (userInput == 't')
        {
            GetNewline();
            ListTopMovies(userNode);
            printf("\n");
        }
        else if (userInput == 'c')
        {
            GetNewline();
            Person_Node* newUser = ChangeUser(head);
            if (newUser != NULL)
            {
                userNode = newUser;
            }
        }
    }
}

//outputs option's regarding the name list
Person_Node* NameOptions(Person_Node* head)
{
    char userInput = ' ';

    while (userInput != 'q')
    {
        printf("Name Menu\n");
        printf("a - Add a name\n");
        printf("r - Remove a name\n");
        printf("q - Quit\n");

        printf("\nChoose an option:\n");
        scanf(" %c", &userInput);
        printf("\n");

        //adds a name to the Person_Node linked list in alphabetical order
        if (userInput == 'a')
        {
            GetNewline();
            head = AddName(head);
            printf("\n");
        }
        else if (userInput == 'r')
        {
            GetNewline();
            head = RemoveName(head);

            printf("\n");
        }

    }
    GetNewline();
    return head;
}
