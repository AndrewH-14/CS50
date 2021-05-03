#include "helpers.h"
#include <math.h>
#include<stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // printf("%i\n", image[0][0].rgbtRed);
    // printf("%i\n", image[0][0].rgbtGreen);
    // printf("%i\n", image[0][0].rgbtBlue);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = (float)((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            int color = round(avg);
            image[i][j].rgbtRed = color;
            image[i][j].rgbtGreen = color;
            image[i][j].rgbtBlue = color;
        }
    }
    //printf("%i\n", image[0][0].rgbtBlue);
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round((0.393 * (float)image[i][j].rgbtRed) + (0.769 * (float)image[i][j].rgbtGreen) + (0.189 *
                                 (float)image[i][j].rgbtBlue));
            int sepiaGreen = round((0.349 * (float)image[i][j].rgbtRed) + (0.686 * (float)image[i][j].rgbtGreen) + (0.168 *
                                   (float)image[i][j].rgbtBlue));
            int sepiaBlue = round((0.272 * (float)image[i][j].rgbtRed) + (0.534 * (float)image[i][j].rgbtGreen) + (0.131 *
                                  (float)image[i][j].rgbtBlue));

            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE tempColor;
            if (j < width - j - 1)
            {
                tempColor = image[i][j];
                image[i][j] = image[i][width - j - 1];
                image[i][width - j - 1] = tempColor;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //printf("%i %i %i %i %i %i\n", image[0][1].rgbtRed, image[0][0].rgbtRed, image[1][0].rgbtRed, image[1][1].rgbtRed, image[1][2].rgbtRed, image[0][2].rgbtRed);
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)
            {
                image[i][j].rgbtRed = round((float)(copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j +
                                                    1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((float)(copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j +
                                                      1].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = round((float)(copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j +
                                                     1].rgbtBlue) / 4.0);
            }
            else if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtRed = round((float)(copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j +
                                                    1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((float)(copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i - 1][j +
                                                      1].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = round((float)(copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i - 1][j +
                                                     1].rgbtBlue) / 4.0);
            }
            else if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtRed = round((float)(copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i + 1][j -
                                                    1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((float)(copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i + 1][j -
                                                      1].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = round((float)(copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i + 1][j -
                                                     1].rgbtBlue) / 4.0);
            }
            else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = round((float)(copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j -
                                                    1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((float)(copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j -
                                                      1].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = round((float)(copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j -
                                                     1].rgbtBlue) / 4.0);
            }
            else if (i == 0)
            {
                image[i][j].rgbtRed = round((float)(copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i +
                                                    1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed + copy[i][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((float)(copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i +
                                                      1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen + copy[i][j + 1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round((float)(copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i +
                                                     1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue + copy[i][j + 1].rgbtBlue) / 6.0);
            }
            else if (j == 0)
            {
                image[i][j].rgbtRed = round((float)(copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j +
                                                    1].rgbtRed + copy[i + 1][j + 1].rgbtRed + copy[i + 1][j].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((float)(copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j +
                                                      1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round((float)(copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j +
                                                     1].rgbtBlue + copy[i + 1][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue) / 6.0);
            }
            else if (i == height - 1)
            {
                image[i][j].rgbtRed = round((float)(copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i -
                                                    1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((float)(copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i -
                                                      1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j + 1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round((float)(copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i -
                                                     1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j + 1].rgbtBlue) / 6.0);
            }
            else if (j == width - 1)
            {
                image[i][j].rgbtRed = round((float)(copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i][j -
                                                    1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((float)(copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i][j -
                                                      1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round((float)(copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i][j -
                                                     1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue) / 6.0);
            }
            else
            {
                image[i][j].rgbtRed = round((float)(copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i][j -
                                                    1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed + copy[i][j +
                                                            1].rgbtRed + copy[i - 1][j + 1].rgbtRed) / 9.0);
                image[i][j].rgbtGreen = round((float)(copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i][j -
                                                      1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen + copy[i][j + 1].rgbtGreen +
                                                      copy[i - 1][j + 1].rgbtGreen) / 9.0);
                image[i][j].rgbtBlue = round((float)(copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i][j -
                                                     1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i
                                                             - 1][j + 1].rgbtBlue) / 9.0);
            }
        }
    }
    //printf("%i\n", image[0][1].rgbtRed);
    return;
}
