#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //defines integer of height
    int height;

    //do while loop which continually prompts user for height which is an integer less than 8.
    do
    {
        height = get_int("Height:");
    }
    while (height > 8 || height < 1);

    int bricks = height;
    int spaces = 0;

    // does this for appropriate number rows based on height
    for (int row = 0; row < height; row++)
    {
        //prints appropriate number of spaces on row
        for (spaces < height;)
            {
                printf(" ");
                spaces++;
            }

            //prints appropriate number of bricks on row
            for (int bricks = 0; bricks < height; bricks++)
            {
                printf("#");
            }

            //prints gap
                printf("  ");

            //prints appropriate number of bricks on row
            // for (int bricks = 0; bricks < height; bricks++)
            // {
            //     printf("#");
            // }

            //creates new line
            printf("\n");

    }




}