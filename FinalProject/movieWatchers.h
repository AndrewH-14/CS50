#ifndef MOVIEWATCHERS_H
#define MOVIEWATCHERS_H

typedef struct movienode
{
    char* Title;
    int rating;
    struct movienode* nextNodePtr;

} Movie_Node;

typedef struct personnode
{
    char* name;
    int numMovies;
    Movie_Node* movieHead;
    struct personnode* nextPersonNode;

} Person_Node;

void GetName(char* name);

void GetTitle(char* title);

int GetRating();

void GetNewline();

Person_Node* AddName(Person_Node* head);

Person_Node* RemoveName(Person_Node* head);

void freePerson(Person_Node* toBeDeleted);

void freeAll(Person_Node* head);

void freeMovie(Movie_Node* node);

void AddMovie(Person_Node* userNode);

void ListAllMovies(Person_Node* userNode);

void ListTopMovies(Person_Node* userNode);

Person_Node* ChangeUser(Person_Node* head);

void RemoveMovie(Person_Node* userNode);

void saveList(Person_Node* head);

int numPeople(Person_Node* head);

Person_Node* loadList(Person_Node* head);

#endif