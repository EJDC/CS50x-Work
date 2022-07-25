#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //defines integer of height
    int height;
    int maxheight = 8;

    //do while loop which continually prompts user for height which is an integer less than 8.
    do
    {
        height = get_int("Height:");
    }
    while (height < 0 && height <= 8);

    //main loop - number of rows based on height

    for (int i = 0; i < height; i++)
        {
            for (int j = -1; (j < i); j++)
            {
                printf("#");
            }

        //for each row, add a number of spaces = height-1

          //  for (int j = spaces; (j <= spaces && j > 0); j--)
      //      {

                //    printf(".");
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