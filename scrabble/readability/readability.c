#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string s);
int count_words(string s);

int main(void)
{
    do
    string s = get_string("Text: ");
    while (s > 1)
    int letters = count_letters(s);
    printf("%i letters\n", letters);
    int words = count_words(s);
    printf("%i words\n", words);
}

int count_letters(string s)
{
    int c = 0;
       for (int i = 0, n = strlen(s); i < n; i++)
           if (isalpha(s[i]))
           {
            c += 1;
           }

        return c;
}

int count_words(string s)
{
    int w = 1;
       for (int i = 0, n = strlen(s); i < n; i++)
           if (isspace(s[i]))
           {
            w += 1;
           }

        return w;
}