#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //defines integer of height
    int height;

    //loop which continually asks for height, if the user enters a height which is less than 1, or greater than 8

    do
    {
        height = get_int("Height:");
    }
    while (height < 1 || height > 8);

    //main loop - number of rows based on height

    for (int i = 0; i < height; i++)
        {
           for (int j = -1; (j < i); j++)
            {
             for (int k = j; (k > 8); k--)
               {
                 printf(".");
               }
                 printf("#");
            }

        //for each row, add a number of spaces = height-1

          //  for (int j = spaces; (j <= spaces && j > 0); j--)
      //      {

                //    printf(".");
          //


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