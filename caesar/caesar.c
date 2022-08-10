#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2 || only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }
    else
    {
        int n = atoi(argv[1]);
        string s;

        do
        {
            s = get_string("plaintext: ");
        }
        while (strlen(s) < 1);

        printf("ciphertext: ");

        for (int i = 0, p = strlen(s); i < p; i++)
        {
            printf("%c", rotate(s[i], n));
        }

        printf("\n");
        return (0);
    }
}

bool only_digits(string s)
{
    bool x = true;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]))
        {
            x = true;
        }
        else
        {
            x = false;
        }
    }

    return (x);

}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (islower(c))
        {
            return ((((c - 97) + n) % 26) + 97);
        }
        else
        {
            return ((((c - 65) + n) % 26) + 65);
        }
    }

    return (c);

}
