#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead)
{
    /* implementation */
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
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    e->phone = NULL;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    return e;
}
