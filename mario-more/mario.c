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

          // nested loop - prints spaces

          for (int k = height - 1; (k > i); k--)
              {
                 printf(".");
              }

          // nested loop - prints left side hashes

           for (int j = -1; (j < i); j++)
               {
                 printf("#");
               }


        //for each row, add a new line.

             printf("\n");

         }
}