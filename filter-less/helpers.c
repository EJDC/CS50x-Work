#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculate rounded average
            int n = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtRed = n;
            image[i][j].rgbtBlue = n;
            image[i][j].rgbtGreen = n;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculate sepia
            int red = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int blue = round(.272 * image[i][j].rgbtRed  + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            int green = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);

            //round down to 255 if needed
            if (red > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = red;
            }

            if (blue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = blue;
            }

            if (green > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = green;
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
        //only iterate through half the image this time
        for (int j = 0; j < width / 2; j++)
        {
            //store left hand side original pixel in temp variable
            int tempRed = image[i][j].rgbtRed;
            int tempBlue = image[i][j].rgbtBlue;
            int tempGreen = image[i][j].rgbtGreen;

            //change  currently iterated pixel to it's opposite side (example: width 4 - (0+1) = 3, width 4 - (1+1) = 2)
            image[i][j].rgbtRed = image[i][width - (j + 1)].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - (j + 1)].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - (j + 1)].rgbtGreen;

            //make the opposite side the temporary variable
            image[i][width - (j + 1)].rgbtRed = tempRed;
            image[i][width - (j + 1)].rgbtBlue = tempBlue;
            image[i][width - (j + 1)].rgbtGreen = tempGreen;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //copy entire image in temp array of triples, as pixel values in the original array will be changed as we iterate through.
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j]
        }
    }

    //loop through each pixel in the temp array
    for (int i = 0; k < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float total_red = 0;
            float total_blue = 0;
            float total_green = 0;
            int divider = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                if (i + k < 0 || i + k >= height)
                {
                    continue;
                }
                if (j + l < 0 || j + l >= width)
                {
                    continue;
                }

                total_red += temp[i + k][j + l].rgbtRed;
                total_blue += temp[i + k][j + l].rgbtBlue;
                total_green += temp[i + k][j + l].rgbtGreen;
                divider++;
                }
            }

            image[i][j].rgbtRed = round(total_red / divider);
            image[i][j].rgbtGreen = round(total_green / divider);
            image[i][j].rgbtBlue = round(total_blue / divider);

        }
    }


    return;
}
