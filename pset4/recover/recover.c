#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Cannot open file\n");
        return 1;
    }
    BYTE buffer[512];
    int count = 0;
    FILE *img = NULL;
    //till the end of file
    while (!feof(file))
    {
        //read chunks of 512 bytes at a time and return number that were read
        int numBytes = fread(&buffer, sizeof(BYTE), 512, file);
        //if it's the start of a jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            char filename[7];
            //if first jpg
            if (count == 0)
            {
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                fwrite(&buffer, sizeof(BYTE), 512, img);
                count++;
            }
            else
            {
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                fwrite(&buffer, sizeof(BYTE), 512, img);
                count++;
            }
        }
        else
        {
            //if the end of the jpg has not been reached
            if (img != NULL)
            {
                if (numBytes == 512)
                {
                    fwrite(&buffer, sizeof(BYTE), 512, img);
                }
                else
                {
                    fwrite(&buffer, sizeof(BYTE), numBytes, img);
                    fclose(img);
                }
            }
        }
    }
    return 0;
}
