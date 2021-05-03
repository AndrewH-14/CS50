#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "movieWatchers.h"

#define MAXLENGTH 50

//Gets any floating newline characters
void GetNewline()
{
    char c = ' ';
    while ((c = getchar()) != EOF && c != '\n');
}

//scans for a name and removes newline
void GetName(char* name)
{
    fgets(name, MAXLENGTH, stdin);

    for (int i = 0; i < MAXLENGTH; i++)
    {
        if (name[i] == '\n')
        {
            name[i] = '\0';
        }
    }
}

//uses fgets to scan line and then removes the newline that was added
void GetTitle(char* title)
{
    fgets(title, MAXLENGTH, stdin);

    for (int i = 0; i < MAXLENGTH; i++)
    {
        if (title[i] == '\n')
        {
            title[i] = '\0';
        }
    }
}

//returns a rating integer
int GetRating()
{
    int rating = 0;
    printf("Enter your rating (1 - 10)\n");
    scanf("%i", &rating);

    return rating;
}

//Adds a name to the person list
Person_Node* AddName(Person_Node* head)
{
    int MaxLength = 40;
    char newName[MaxLength];
    printf("Enter new name to add:\n");
    GetName(newName);

    //creating a new person node and initlizing the information
    Person_Node* newNode = (Person_Node*)malloc(sizeof(Person_Node));
    newNode->nextPersonNode = NULL;
    newNode->movieHead = NULL;
    newNode->name = (char*)malloc(sizeof(strlen(newName) + 1));
    strcpy(newNode->name, newName);

    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    //checks for duplicate names
    for (Person_Node* cur = head; cur->nextPersonNode != NULL; cur = cur->nextPersonNode)
    {
        if (strcmp(cur->name, newName) == 0)
        {
            printf("Name already exists, Not Added\n");
            return head;
        }
    }

    if (newName[0] < head->name[0])
    {
        newNode->nextPersonNode = head;
        return newNode;
    }
    else
    {
        Person_Node* prev = head;

        while(prev->nextPersonNode != NULL)
        {
            if (newNode->name[0] < prev->nextPersonNode->name[0])
            {
                break;
            }
            prev = prev->nextPersonNode;
        }

        newNode->nextPersonNode = prev->nextPersonNode;
        prev->nextPersonNode = newNode;

        return head;
    }
}

//free's a specific person node
void freeName(Person_Node* toBeDeleted)
{
    if (toBeDeleted->movieHead == NULL)
    {
        free(toBeDeleted);
    }
    else
    {
       Movie_Node* head = toBeDeleted->movieHead;
       while (head != NULL)
       {
           Movie_Node* next = head->nextNodePtr;
           free(head->Title);
           free(head);
           head = next;
       }
       free(toBeDeleted);
    }
}

//free's the entire list
void freeAll(Person_Node* head)
{
    for (Person_Node* cur = head; cur != NULL; cur = cur->nextPersonNode)
    {
    Movie_Node* movieHead = cur->movieHead;
       while (movieHead != NULL)
       {
           Movie_Node* next = movieHead->nextNodePtr;
           free(movieHead);
           movieHead = next;
       }
    }

    while (head != NULL)
    {
        Person_Node* next = head->nextPersonNode;
        free(head);
        head = next;
    }
}

void freeMovie(Movie_Node* node)
{
    free(node->Title);
    free(node);
}

//Removes a name from the persons list
Person_Node* RemoveName(Person_Node* head)
{
    char name[MAXLENGTH];
    printf("Enter name to remove:\n");
    GetName(name);

    if (head == NULL)
    {
        printf("No names in list\n");
        return head;
    }

    for (Person_Node* cur = head; head->nextPersonNode != NULL; cur = cur->nextPersonNode)
    {
        if (strcmp(cur->name, name) == 0)
        {
            break;
        }
        else if (cur->nextPersonNode == NULL)
        {
            printf("Name could not be found\n");
            return head;
        }
    }

    if (strcmp(head->name, name) == 0)
    {
        Person_Node* newHead = head->nextPersonNode;
        freeName(head);
        return newHead;
    }
    else
    {
        Person_Node* prev = head;

        while (prev->nextPersonNode != NULL)
        {
            if (strcmp(prev->nextPersonNode->name, name) == 0)
            {
                break;
            }
            prev = prev->nextPersonNode;
        }

        Person_Node* toBeDeleted = prev->nextPersonNode;
        prev->nextPersonNode = prev->nextPersonNode->nextPersonNode;

        free(toBeDeleted);
        return head;
    }
}

//adds a movie to a persons list
void AddMovie(Person_Node* userNode)
{
    // initliazes the new movie node and gets the information needed
    int MaxLength = 40;
    char title[MaxLength];

    GetTitle(title);

    //initilizing a new movie node
    Movie_Node* newNode = (Movie_Node*)malloc(sizeof(Movie_Node));
    newNode->Title = (char*)malloc(sizeof(strlen(title) + 1));
    strcpy(newNode->Title, title);
    newNode->rating = GetRating();
    newNode->nextNodePtr = NULL;

    // adds the new node to the users movie list
    if (userNode->movieHead == NULL)
    {
        userNode->movieHead = newNode;
        userNode->numMovies++;
        return;
    }

    //checking for duplicates
    for (Movie_Node* cur = userNode->movieHead; cur != NULL; cur = cur->nextNodePtr)
    {
        if (strcmp(newNode->Title, cur->Title) == 0)
        {
            printf("Movie already in list\n");
            return;
        }
    }

    if (userNode->movieHead->rating < newNode->rating)
    {
        newNode->nextNodePtr = userNode->movieHead;
        userNode->movieHead = newNode;
    }
    else
    {
        Movie_Node* prev = userNode->movieHead;

        while (prev->nextNodePtr != NULL)
        {
            if (newNode->rating > prev->rating)
            {
                break;
            }
            prev = prev->nextNodePtr;
        }

        newNode->nextNodePtr = prev->nextNodePtr;
        prev->nextNodePtr = newNode;
    }
    userNode->numMovies++;
}

//lists all the movies (with their ratings) watched by the user
void ListAllMovies(Person_Node* userNode)
{
    printf("Title | Rating\n");
    for (Movie_Node* cur = userNode->movieHead; cur != NULL; cur = cur->nextNodePtr)
    {
        printf("%s | %i\n", cur->Title, cur->rating);
    }
}

// list a certain number of users top movies
void ListTopMovies(Person_Node* userNode)
{
    int numMovies = 0;
    printf("How many movies would you like to list:\n");
    scanf("%i", &numMovies);

    Movie_Node* cur = userNode->movieHead;

    printf("\nTitle | Rating\n");

    for (int i = 0; i < numMovies; i++)
    {
        if (cur != NULL)
        {
            printf("%s | %i\n", cur->Title, cur->rating);
        }
        cur = cur->nextNodePtr;
    }
}

// changes the user in the movie menu
Person_Node* ChangeUser(Person_Node* head)
{
    char name[MAXLENGTH];
    printf("Enter name of new user:\n");
    GetName(name);

    for (Person_Node* cur = head; cur != NULL; cur = cur->nextPersonNode)
    {
        if (strcmp(name, cur->name) == 0)
        {
            return cur;
        }
    }
    printf("Unable to find user\n");
    return NULL;
}

// removes a specified movie from a persons list
void RemoveMovie(Person_Node* userNode)
{
    char title[MAXLENGTH];
    printf("Enter movie title to remove:\n");
    GetTitle(title);

    if (userNode->movieHead == NULL)
    {
        printf("No movies in list\n");
        return;
    }

    for (Movie_Node* cur = userNode->movieHead; cur != NULL; cur = cur->nextNodePtr)
    {
        if (strcmp(title, cur->Title) == 0)
        {
            break;
        }
        else if (cur->nextNodePtr == NULL)
        {
            printf("Title not in list\n");
            return;
        }
    }

    if (strcmp(userNode->movieHead->Title, title) == 0)
    {
        Movie_Node* newHead = userNode->movieHead->nextNodePtr;
        freeMovie(userNode->movieHead);
        userNode->movieHead = newHead;
    }
    else
    {
        Movie_Node* prev = userNode->movieHead;

        while (prev->nextNodePtr != NULL)
        {
                if (strcmp(prev->nextNodePtr->Title, title) == 0)
                {
                    break;
                }
                prev = prev->nextNodePtr;
        }

        Movie_Node* toBeDeleted = prev->nextNodePtr;
        prev->nextNodePtr = prev->nextNodePtr->nextNodePtr;
        freeMovie(toBeDeleted);
    }
    userNode->numMovies--;
}

//returns the number of people in the list
int numPeople(Person_Node* head)
{
    int num = 0;
    for (Person_Node* cur = head; cur != NULL; cur = cur->nextPersonNode)
    {
        num++;
    }
    return num;
}

// saves a list to a text file
void saveList(Person_Node* head)
{
    FILE* file = fopen("List.txt", "w");
    if (!file)
    {
        printf("Unable to save list\n");
        return;
    }

    int numOfPeople = numPeople(head);
    fprintf(file, "%i\n", numOfPeople);

    for (Person_Node* cur = head; cur != NULL; cur = cur->nextPersonNode)
    {
        Movie_Node* curMovie = cur->movieHead;

        fprintf(file, "%s\n%i\n", cur->name, cur->numMovies);

        for (int i = 0; i < cur->numMovies; i++)
        {
            fprintf(file, "%s\n%i\n", curMovie->Title, curMovie->rating);
            curMovie = curMovie->nextNodePtr;
        }
    }
    fclose(file);
}

//gets line of txt from file
void GetLineFromFile(char* line, FILE* file)
{
    fgets(line, MAXLENGTH, file);
    //printf("%s\n", line);

    for (int i = 0; i < MAXLENGTH; i++)
    {
        if (line[i] == '\n')
        {
            line[i] = '\0';
        }
    }
    //printf("%s\n", line);
}

//creates a movie node from file
Movie_Node* CreateMovieFromFile(FILE* file)
{
    char line[MAXLENGTH];
    GetLineFromFile(line, file);

    Movie_Node* newMovie = (Movie_Node*)malloc(sizeof(Movie_Node));
    newMovie->nextNodePtr = NULL;
    newMovie->Title = (char*)malloc(sizeof(strlen(line) + 1));
    strcpy(newMovie->Title, line);

    GetLineFromFile(line, file);
    int rating = atoi(line);

    newMovie->rating = rating;

    return newMovie;
}

//Adds a movie node at end of list
void AddMovieAtBack(Person_Node* userNode, Movie_Node* newMovie)
{
    if (userNode->movieHead == NULL)
    {
        userNode->movieHead = newMovie;
        return;
    }
    else
    {
        for (Movie_Node* cur = userNode->movieHead; cur != NULL; cur = cur->nextNodePtr)
        {
            if (cur->nextNodePtr == NULL)
            {
                cur->nextNodePtr = newMovie;
                break;
            }
        }
    }

}

//Creates a new person node from information in the txt file
Person_Node* CreatePersonFromFile(FILE* file)
{
    char line[MAXLENGTH];
    GetLineFromFile(line, file);
    //printf("hello\n", line);

    Person_Node* newPerson = (Person_Node*)malloc(sizeof(Person_Node));
    newPerson->movieHead = NULL;
    newPerson->name = (char*)malloc(sizeof(strlen(line) + 1));
    strcpy(newPerson->name, line);

    GetLineFromFile(line, file);
    int numMovies = atoi(line);

    newPerson->numMovies = numMovies;

    for (int i = 0; i < numMovies; i++)
    {
        Movie_Node* newMovie = CreateMovieFromFile(file);
        AddMovieAtBack(newPerson, newMovie);
    }

    return newPerson;
}

//loads list from previous use from a txt file
Person_Node* loadList(Person_Node* head)
{
    FILE* file = fopen("List.txt", "r");
    if (!file)
    {
        printf("Unable to load list\n");
        return NULL;
    }

    char num[MAXLENGTH];
    GetLineFromFile(num, file);
    int numPeople = atoi(num);
    printf("%i\n", numPeople);

    for (int i = 0; i < numPeople; i++)
    {
        if (i == 0)
        {
            head = CreatePersonFromFile(file);
        }
    }

    fclose(file);

    return head;
}