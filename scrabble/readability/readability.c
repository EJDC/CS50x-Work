#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>


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
    printf("%i sentences\n", sents);

float al = (100 / letters) * 100;
float as = (100 / sents) * 100;
float grade = (0.588 * al) - (0.296 * as) - 15.8;
printf("%f grade\n", grade);

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

int count_sentences(string s)
{
    int t = 0;
       for (int i = 0, n = strlen(s); i < n; i++)
           if (s[i] == 33 || s[i] == 46 || s[i] == 63)
           {
            t += 1;
           }

        return t;
}