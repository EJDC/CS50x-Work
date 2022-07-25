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

int maxHeight = 8;
int spaces = height -1;

    //main loop - number of rows based on height

    for (int i = 0; i < height; i++)
        {
            for

        //for each row, add a number of spaces = height-1

          //  for (int j = spaces; (j <= spaces && j > 0); j--)
      //      {

                    printf(".");
        //    }


        //for each row, add a number of bricks = height

        //    for (int bricks = 0; bricks < height; bricks++)
        //    {
          //      printf("#");
        //    }

        //for each row, add a gap of two spaces

        //        printf("  ");

        //for each row, add a number of bricks = height

      //       for (int bricks = 0; bricks < height; bricks++)
        //    {
          //      printf("#");
          //  }

        //for each row, add a new line.

             printf("\n");

         }
}