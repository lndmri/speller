// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"


// TODO: Choose number of buckets in hash table
// I chose 523 as it is a prime number to avoid the probability of collisions
const unsigned int N = 523;

// global variable to keep track of all the words loaded
unsigned int loaded = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // index of where the word would be in the dictionary
    unsigned int index = hash(word);
    node *p;
    for (p = table[index]; p != NULL; p = p->next)
    {
        if(strcasecmp(word, p->word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // using sum of ascii values to imporve function
    unsigned int hash_val = 0;
    unsigned int prime = 33;
    int i = 0;

    while(word[i] != '\0')
    {
        hash_val *= prime;
        hash_val += toupper(word[i]);
        i++;
    }

    hash_val = hash_val % N;

    return hash_val;
    // This was the given function by cs50
    // return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dic_file = fopen(dictionary, "r");
    if (dic_file == NULL)
    {
        printf("Error opening dictionary file\n");
        return false;
    }

    point_null(table, N);

    // size of the word
    char word[LENGTH];

    while (fscanf(dic_file, "%s", word) != EOF)
    {
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            printf("Error mallocking on load function\n");
            return false;
        }

        strcpy(new->word, word);
        new->next = NULL;

        // now we use the hash function to find the index of the link list in which we are going to isert the node
        int index = hash(word);
        new->next = table[index];
        table[index] = new;
        loaded++;
    }

    fclose(dic_file);
    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    // This approach uses traversing the hash table and counting each value.
    // node *p;
    // unsigned int count = 0;
    // for (int i = 0; i < N; i++)
    //     for (p = table[i]; p!= NULL; p = p->next)
    //         count++;

    // return count;

    // this approach reduces time as we do not have to traverse the table
    // we created a gloabl variable and incremented it every time we loaded a new value in the load function

    return loaded;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *prev, *cur;
    for (int i = 0; i < N; i++)
    {
        while(table[i] != NULL)
        {
            node *temp = table[i];
            table[i] = table[i]->next;
            free(temp);
        }

        if (table[i] != NULL)
        {
            printf("Error unloading\n");
            return false;
        }
    }

    return true;
}

void print_table(node *hash_table[], int n)
{   node *p;
    for (int i = 0; i < n; i++)
        for(p = hash_table[i]; p != NULL; p = p->next)
            printf("Bucket : %d\tWord: %s\n", i, p->word);

}

void point_null(node *hash_table[], int n)
{
    for(int i = 0; i < n; i++)
    {
        table[i] = NULL;
    }
}

