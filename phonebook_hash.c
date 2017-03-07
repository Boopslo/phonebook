#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead)
{
    // use hash function to create position and add into hash table
    unsigned int hash_position;
    hash_position = hashFunction(lastName);
    pHead = hashTable[hash_position];
    printf("%d\n", hash_position);

    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* implementation */
    unsigned int hash_position;
    hash_position = hashFunction(lastName);
    printf("%d\n", hash_position);

    e = (entry *) malloc(sizeof(entry));
    //strcpy(e->lastName, lastName);
    e->pNext = hashTable[hash_position];
    strcpy(e->lastName, lastName);
    e->phone = NULL;
    hashTable[hash_position] = e;

    return e;
}

// djb2 algorithm
unsigned int hashFunction(char *lastName)
{
    unsigned int hash = 5381;

    while (*lastName)
        hash = ((hash << 5) + hash) + *lastName++;

    // return division
    return (hash % MAX_HASHTABLE_SIZE);
}

