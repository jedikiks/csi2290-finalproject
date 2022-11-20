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








#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Str
{
	char word[50];
}Str;
typedef struct
{
	Str* data;
	int listsize;
	int length;
}Sqlist;
int initSqlist(Sqlist* L, int maxsize)
{
	L->data = (Str*)malloc(maxsize * sizeof(Str));
	if (L->data == NULL) 
	{ printf("Space application failed!"); exit(0); }
	L->listsize = maxsize;
	L->length = 0;
	return 1;
}

int main()
{
	Sqlist L;
	initSqlist(&L, 1000);   //Initialize str, the size is 1000, used to store the segmented words
	char f1[] = "C:\Users\aaron\OneDrive\Documents\GitHub\csi2290-finalproject\Work"; //file location (your d1-d4.txt file location 
	char arr[1024] = { 0 };
	FILE* fp; 
	fp = fopen(f1, "r");
	if (fp == NULL)  //Determine whether reading the file is successful
	{
		printf("file read failed");
		return 1;
	}
	else
	{
		while (fgets(arr, 1013, fp) != NULL) //Read the content of each line in a loop, the first line of di.txt exceeds 1024bit, so it is read twice, and the others are divided once
		{
			char* p = " (),.;/";  //collection of delimiters
			char buf[1024] = { 0 };
			strcpy(buf, arr);    //Copy to the buf array and operate on the buf array
			char* ret = NULL;
			for (ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))  //Use strtok for loop segmentation operation
			{
				strcpy(L.data[L.length].word, ret);  //Store it in the str structure
				L.length++;
			}
		}
	}
	//test：
	for (int i = 0; i < L.length; i++)
	{
		printf("%s\n", L.data[i].word);
	}

	return 0;
}
