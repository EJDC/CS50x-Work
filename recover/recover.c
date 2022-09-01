#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //usage check - 1 command argument
    if (argc != 2)
    {
        printf("Usage:  ./recover file.raw\n");
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("File not found");
        return 1;
    }

    //variables
    //buffer of 512 bytes
    BYTE buffer[512];
    //counter for number of images found
    int counter = 0;
    //output file
    FILE *output_file = NULL;
    //output file name (array of 8 (3 chars + .jpg + \0))
    char* filename[8];

    //repeat until end of card
    while (fread(&buffer, 512, 1, file) == 1)
    {
        //if first bytes are a jpeg header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //make filename (3 digit integer) of counter
            sprintf(filename, "%03i.jpg", counter);

            //open Out_file for writing
            output_file = fopen(filename, "w");

            //iterate counter of number of image found
            counter++;
         }

        if (!(counter == 0))
        {
                fwrite(&buffer, 512, 1, output_file);
        }
    }

    fclose(output_file);
    fclose(file);

    return 0;
}
