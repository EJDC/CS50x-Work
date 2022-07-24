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

    // does this for appropruate number rows based on height
    for (int row = 0; row < height; row++)
    {
        //prints appropriate number of spaces on row
        for (int spaces = 0; (spaces = 8 - height);)
            {
                printf(" ");
            }

            //prints appropriate number of bricks on row
            for (int bricks = 0; (bricks < height);)
            {
                printf("#");
            }

    }




}