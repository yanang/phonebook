#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#include "phonebook_opt_hash.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */

//hash * hashTable =(struct hash *) calloc(256,sizeof(struct hash));
unsigned int BKDRHash(char *stri)
{
    unsigned int seed = 131;
    unsigned int hash = 0;

    while(*stri) {
        hash = hash * seed + (*stri++);
    }
    return( (hash & 0x7FFFFFFF) % 1024);
}


entry *findName(char lastName[], entry *e[])
{
    unsigned int hash = BKDRHash(lastName);
    entry *pGoal = e[hash];
    while(pGoal != NULL) {
        if(strcasecmp(pGoal->lastName,lastName)==0)
            return  pGoal;
        pGoal = e[hash] -> pNext;
    }
    return NULL;
}

void *append(char lastName[], entry *e[])
{
    unsigned int hash = BKDRHash(lastName);

    if(!e[hash]) {
        e[hash] = (entry *) malloc (sizeof(entry));
        e[hash] -> pNext = NULL;
        strcpy(e[hash]->lastName,lastName);
    } else {
        entry *pHead = (entry *) malloc (sizeof(entry));
        pHead -> pNext = e[hash];
        e[hash] = pHead;
        strcpy(pHead->lastName,lastName);
        /*        entry *pLast = (entry *) malloc (sizeof(entry));
                  pLast -> pNext = NULL ;
                  strcpy(pLast->lastName,lastName);
                  e[hash] -> pNext = pLast;
                  //not finished
                  //should add loop to find the last data
        */
    }
    return NULL;
}
