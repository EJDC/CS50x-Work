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
        //for each row, add a number of spaces = height-1
        {
            for (int spaces = (height - 1); spaces ++)
            printf(" ")
                    }

        //for each row, add a number of bricks = height
        //for each row, add a gap of two spaces
        //for each row, add a number of bricks = height
        //for each row, add a new line.





    // does this for appropriate number rows based on height

    {
        //prints appropriate number of spaces on row
        for (int spaces = 0; spaces < height ; spaces++)
            {
                printf(" ");
            }

            //prints appropriate number of bricks on row
            for (int bricks = 0; bricks < height; bricks++)
            {
                printf("#");
            }

            //prints gap
                printf("  ");

            //prints appropriate number of bricks on row
            for (int bricks = 0; bricks < height; bricks++)
            {
                printf("#");
            }

            //creates new line
            printf("\n");

    }




}