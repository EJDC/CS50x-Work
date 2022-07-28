#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    string s;

    do
    s = get_string("Text: ");
    while (strlen(s) < 1);

    float letters = count_letters(s);
   // printf("%f letters\n", letters);
    float words = count_words(s);
  //  printf("%f words\n", words);
    float sents = count_sentences(s);
  //  printf("%f sentences\n", sents);

float al = (letters / words) * 100;
//printf("%f average letters\n", al);

float as = (sents / words) * 100;
//printf("%f average sentences\n", as);

int grade = round(0.0588 * al - 0.296 * as -15.8);

printf("Grade %i\n", grade);

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