#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char *data;
    struct Node* next;
} Node;

void insertEnd( struct Node** root, char *data, size_t size );
void traverse( struct Node* root );
void freeList( struct Node** root );


int main(){

    Node* root = malloc( sizeof( Node ) );                      // Create root node 
    if( !root ){
        fputs( "ERROR: Could not create root node", stderr );
        exit( EXIT_FAILURE );
    }
    root->next = NULL;

    FILE *text1, *text2, *text3, *text4; *out1, *out2, *out3, *out4;
	
	text1 = fopen("../assets/d1.txt", "r");
	text2 = fopen("../assets/d2.txt", "r");
	text3 = fopen("../assets/d3.txt", "r");
	text4 = fopen("../assets/d4.txt", "r");
	

	out1 = fopen("../assets/outd1.txt", "w");				/*the text files for the final outputs*/
	out2 = fopen("../assets/outd2.txt", "w");
	out3 = fopen("../assets/outd3.txt", "w");
	out4 = fopen("../assets/outd4.txt", "w");
	
	
	
	
	/*copied from internet:
	
	syntax: char *strtok(char *str, const char *delim)

	Breaks string str into a series of tokens separated by delim.
	
	We might be able to delimit (separate) the strings read from our text files by setting the delimiter equal to spacebar
	
	I would also recommend visiting this link for ideas: https://www.tutorialspoint.com/c_standard_library/string_h.htm
	*/

	fclose(text1);
	fclose(text2);
	fclose(text3);
	fclose(text4);
	fclose(out1);
	fclose(out2);
	fclose(out3);
	fclose(out4);
    freeList( &root );
    return 0;
}

void insertEnd( Node** root, char *data, size_t size ){
    Node* newNode = malloc( sizeof( Node ) );
        if( !newNode ){
            fputs( "ERROR: Could not insert node", stderr );
            exit( EXIT_FAILURE );                           // TODO: Should we exit?
        }
    newNode->next = NULL;
    memcpy( newNode->data, &data, size );                    // Copy data array to new node's data
    
    if( !*root ){                                           // If we try to insert when root node
        *root = newNode;                                    // is NULL, we make the pointer to
        return;                                             // root equal to our new node.
    }                                                       // This is why we pass Node** root

    Node* currentNode = *root;                              // Iterate through linked list
    while( !currentNode->next ){                            // until the next node is NULL
        currentNode = currentNode->next;                    // ( this is the last one )
    }

    currentNode->next = newNode;
}

void traverse( struct Node* root ){
    Node* currentNode = root;
    if( !currentNode ){
        currentNode = currentNode->next;
        traverse( currentNode );
    }
}

void freeList( struct Node** root ){
    Node* currentNode = *root;
                                                            // Two pointers: prevNode points to
    Node* previousNode = currentNode;                       // node to be freed && currentNode
    currentNode = currentNode->next;                        // moves to the next node.
    free( currentNode->data );                              // TODO: Is this necessary?
    free( previousNode );
    
    if( !currentNode ){
        freeList( &currentNode );
    }

    *root = NULL;                                           // Implies list is empty
}
