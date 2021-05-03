#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    // left aligning pyramid
    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < i + 1; j++) {
    //         printf("#");
    //     }
    //     printf("\n");
    // }

    // right aligning pyramid
    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < h; j++)
    //     {
    //         if (j >= h - i - 1)
    //         {
    //             printf("#");
    //         }
    //         else
    //         {
    //             printf(" ");
    //         }
    //     }
    //     printf("\n");
    // }
    
    //pyramid with two spaces in the middle
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (j >= h - i - 1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("  ");
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}