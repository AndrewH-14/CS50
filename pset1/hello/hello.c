#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //prompting user for name
    string name = get_string("What is your name?\n");
    //printing response
    printf("hello, %s\n", name);
}
