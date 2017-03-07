#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define HASH 1
// #define DJB2 1
#define MAX_HASHTABLE_SIZE 50671

typedef struct __PHONEBOOK_ENTRY {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} phonebook_entry;


typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    phonebook_entry *phone;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

// hash table to store lastName
entry *hashTable[MAX_HASHTABLE_SIZE];

unsigned int hashFunction(char *);

entry *findName(char lastName[], entry *pHead);
entry *append(char lastName[], entry *e);

#endif
