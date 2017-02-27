#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LAST_NAME_SIZE 16
#define OPT_HASH 1
/* hash */
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
//    char firstName[16];
//    char email[16];
//    char phone[10];
//    char cell[10];
//    char addr1[16];
//    char addr2[16];
//    char city[16];
//   char state[2];
//    char zip[5];
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

unsigned int BKDRHash(char * stri);
entry *findName(char lastName[], entry *e[]);
void *append(char lastName[], entry *e[]);

#endif
