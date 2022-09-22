// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//dictionary size global variable
int wordcount = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //defines a variable hashval which calls the hash function on the  word, resulting in an integer hash value which would be the start of the linked list.
    int hashval = hash(word);

    //access the linked list of nodes at the hashval (ie start of list)
    node *x = table[hashval]

    //go through the nodes in the linked list to look for the word.
    while (x != NULL)
    {
        if (strcasecmp(word, x->word) == 0)
        {
            return true;
        }

        x = x->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //open dictionary file
    FILE *dictfile = fopen(dictionary, "r");

    //check if return value is NULL.
    if (!dictfile)
    {
        printf("Dictionary file not found");
        return false;
    }

    //create array of characters for new word [of size maxworthlenghth as defined in other file +1 for the old /0]
    char newWord[LENGTH + 1];

    //loop to read strings (%s) from the file (dictfile) and store in array (word) until the end of the file.
    while (fscanf(dictfile, "%s", newWord) != EOF)
    {
        //create a new node (of size node) for the current word each time we loop.
        node *newNode = malloc(sizeof(node));

        //if we run out of memory, the memory allocated will be NULL so exit out of the programme.
        if (!newNode)
        {
            return false;
        }

        //copy new word into the new node with a string copy.
        strcpy(newNode->word, newWord);

        //defines a variable hashval which calls the hash function on the new word, resulting in an integer hash value
        int hashval = hash(newWord);

        //point new node to beginning of linked list, which is the hashval which we stated above.
        newNode->next = table[hashval];

        //insert node at (hashval) location in hash table
        table[hashval] = newNode;

        //increase the word count
        wordcount++;

    }

    fclose(dictfile);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
