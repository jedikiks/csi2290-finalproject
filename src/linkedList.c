#include "linkedList.h"

typedef struct Node Node;


void 
insertEnd( Node** root, char data[] ){
    Node* newNode = malloc( sizeof( Node ) );
        if( !newNode ){
            fputs( "WARNING: Could not insert node", stderr );
        }

    newNode->next = NULL;
    memcpy( newNode->data, data, strlen( data ) + 1 );      // Copy string to new node's data
    
    if( !*root ){                                           // If we try to insert when root node
        *root = newNode;                                    // is NULL, we make the pointer to
        return;                                             // root equal to our new node.
    }                                                       // This is why we pass Node** root

    Node* currentNode = *root;                              // Iterate through linked list
    while( currentNode->next != NULL ){                            // until the next node is NULL
        currentNode = currentNode->next;                    // ( this is the last one )
    }

    currentNode->next = newNode;
}

void 
traverse( struct Node* root ){
    for( Node* currentNode = root; currentNode != NULL; currentNode = currentNode->next ){
        printf( "%s\n", currentNode->data );
    }
}

void 
freeList( struct Node** root ){
    Node* currentNode = *root;
                                                            // Two pointers: prevNode points to
    Node* previousNode = currentNode;                       // node to be freed && currentNode
    currentNode = currentNode->next;                        // moves to the next node.
    free( previousNode );
    
    if( currentNode != NULL ){
        freeList( &currentNode );
    }

    *root = NULL;                                           // Implies list is empty
}
