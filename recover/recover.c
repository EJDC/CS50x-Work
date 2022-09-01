#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //usage check - 1 command argument
    if (argc != 2)
    {
        printf("Usage:  ./recover file.raw")
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return 1;
    }

    // Read first three bytes
    BYTE bytes[3];
    fread(bytes, sizeof(BYTE), 3, file);

    // Check first three bytes
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("Yes, possibly\n");
    }
    else
    {
        printf("No\n");
    }



}