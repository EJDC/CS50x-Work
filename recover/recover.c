#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //usage check - 1 command argument
    if (argc != 2)
    {
        printf("Usage:  ./recover file.raw\n")
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("File not found")
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
    char filename[8];

    //repeat until end of card
    while (fread(buffer, 1, 512, raw_file) == 512)
    {
    //if first bytes are a jpeg header
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)


    }

    // Read first three bytes
    BYTE bytes[3];
    fread(bytes, sizeof(BYTE), 3, file);

    // Check first three bytes
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && bytes[3] (buffer[3] & 0xf0) == 0xe0)
    {
        printf("Yes, possibly\n");
    }
    else
    {
        printf("No\n");
    }



}