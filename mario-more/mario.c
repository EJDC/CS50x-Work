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


    //main loop - number of rows based on height

    for (int row = 0; row < height; row++)
        {

        //for each row, add a number of spaces = height-1

            for (int spaces = (height -1); spaces < height; spaces++)
            {
            printf(" ");
            }

        //for each row, add a number of bricks = height

            for (int bricks = 0; bricks < height; bricks++)
            {
                printf("#");
            }

        //for each row, add a gap of two spaces

                printf("  ");

        //for each row, add a number of bricks = height

             for (int bricks = 0; bricks < height; bricks++)
            {
                printf("#");
            }

        //for each row, add a new line.

            printf("\n");

         }
}