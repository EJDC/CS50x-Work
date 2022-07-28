#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    string s;

    do
    s = get_string("Text: ");
    while (strlen(s) < 1);

    int letters = count_letters(s);
    printf("%i letters\n", letters);
    int words = count_words(s);
    printf("%i words\n", words);
    int sents = count_sentences(s);
    printf("%i sents\n", sentences);
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

int count_sentences(string s);
{
    int c = 0;
       for (int i = 0, n = strlen(s); i < n; i++)
           if (strcomp(s[i]))
           {
            c += 1;
           }

        return c;
}