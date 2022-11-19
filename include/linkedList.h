#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STRSIZE 50 

typedef struct Node{
    char data[STRSIZE];
    struct Node* next;
} Node;

void insertEnd( struct Node** root, char data[] );
void traverse( struct Node* root );
void freeList( struct Node** root );
