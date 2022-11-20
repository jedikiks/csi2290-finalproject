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

int
main(){

    Node* root = malloc( sizeof( Node ) );                      // Create root node 
    if( !root ){
        fputs( "ERROR: Could not create root node", stderr );
        exit( EXIT_FAILURE );
    }

    // Uncomment the following block to test linked list:
    /*
    char word[ STRSIZE ] = "super mario brothers 2";
    insertEnd( &root, word );
    traverse( root );
    */

//    FILE *text1, *text2, *text3, *text4;
//	
//	text1 = fopen("../assets/d1.txt", "r");
//	text2 = fopen("../assets/d2.txt", "r");
//	text3 = fopen("../assets/d3.txt", "r");
//	text4 = fopen("../assets/d4.txt", "r");
	
	/*must decide on how best to read and tokenize the data*/
//	while((int c = getchar())!=EOF) {
		
//	}
	
	
	/*copied from internet:
	
	syntax: char *strtok(char *str, const char *delim)

	Breaks string str into a series of tokens separated by delim.
	
	We might be able to delimit (separate) the strings read from our text files by setting the delimiter equal to spacebar
	
	I would also recommend visiting this link for ideas: https://www.tutorialspoint.com/c_standard_library/string_h.htm
	*/

//	fclose(text1);
//	fclose(text2);
//	fclose(text3);
//	fclose(text4);

    freeList( &root );

    return EXIT_SUCCESS;
}

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
