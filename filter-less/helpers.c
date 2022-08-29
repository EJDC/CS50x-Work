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
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            //check if there is a pixel to the left - compare to width of image(?)
            if (temp[i][j - 1] != 0);

                //if there is not a pixel to the left, check above and below it.

                    //if there is a pixel above or below, it's an edge.

                    //if there is not a pixel above or below, it's a corner.

            //check if there is a pixel to the right

                //if there is not a pixel to the left, check above and below it.

                    //if there is a pixel above or below, it's an edge.

                    //if there is not a pixel above or below, it's a corner.

            //otherwise it's a regular one.



                //if there is a pixel in the top right, add the values of the pixel and the one below to calculation. Add 2 to "divider" variable.

            //check if there is a pixel in the bottom right.

                //if there is a pixel in the bottom right, add the values of the pixel and the one to the left to calulation. Add 2 to "divider" variable.

            //check if there is a pixel in the bottom left.

                //if there is a pixel ib the bottom left, add the values of the pixel and the one above to calculation. Add 2 to divider variable.

        }
    }


    return;
}
