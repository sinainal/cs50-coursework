// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
int num = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    node *x = table[hash(word)];
    if (x == NULL)
    {
        return false;
    }
    while (x->next != NULL)
    {
        if (!strcasecmp(word, x->word))
        {
            return true;
        }
        x = x->next;
    }
    if (!strcasecmp(word, x->word))
    {
        return true;
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
    FILE *file = fopen(dictionary, "r");
    char w[LENGTH + 1];
    while (fscanf(file, "%s", w) == 1)
    {
        num++;
        node *n = malloc(sizeof(node));
        strcpy(n->word, w);
        n->next = table[hash(w)];
        table[hash(w)] = n;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return num;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *x = table[i];
        node *tmp = table[i];
        while (x != NULL)
        {
            x = x->next;
            free(tmp);
            tmp = x;
        }
    }
    return true;
}
