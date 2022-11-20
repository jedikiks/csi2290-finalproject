#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*typedef struct Node{
    char *data;
    struct Node* next;
} Node;
*/

/*void insertEnd( struct Node** root, char *data, size_t size );
void traverse( struct Node* root );
void freeList( struct Node** root );*/
FILE *text1, *text2, *text3, *text4, *out, *out2, *out3, *out4, *stopwords, *spec;

FILE *test;								/*for debugging*/

int specdetected = 0;

int main(){
	specialchar1();						/*tokenizes the special characters*/

	/*
    Node* root = malloc( sizeof( Node ) );                      // Create root node 
    if( !root ){
        fputs( "ERROR: Could not create root node", stderr );
        exit( EXIT_FAILURE );
    }
    root->next = NULL;
	*/
	
	text1 = fopen("d1.txt", "r");
	text2 = fopen("d2.txt", "r");
	text3 = fopen("d3.txt", "r");
	text4 = fopen("d4.txt", "r");
	
	test = fopen("test.txt", "w");

	out = fopen("out1.txt", "w");				/*the text files for the final outputs*/
	out2 = fopen("out2.txt", "w");
	out3 = fopen("out3.txt", "w");
	out4 = fopen("out4.txt", "w");
	
	char readone[1500];												/*the array used to store the first text file*/
	int i = 0;														/*each iteration of i represents a new character from the text file read*/
	while ((fgets(readone, sizeof(readone), text1)) != NULL) {
		
		specialchar2(readone[i]);
		
		if (readone[i]!=' ' && readone[i]!='  ') {						/*if there is a space or two spaces, assume the word is over*/
			
			if (specdetected ==1) {												/*if there's a special character, ignore it*/
				continue;
			}
			else {
				fprintf(out,"%c",readone[i]);
			}
		}
		else {
			fprintf(out,"\n");
		}
		
	
		i++;
	}
	
	
	/*copied from internet:
	
	syntax: char *strtok(char *str, const char *delim)

	Breaks string str into a series of tokens separated by delim.
	
	We might be able to delimit (separate) the strings read from our text files by setting the delimiter equal to spacebar
	
	I would also recommend visiting this link for ideas: https://www.tutorialspoint.com/c_standard_library/string_h.htm
	*/

	fclose(test);
	
	fclose(text1);
	fclose(text2);
	fclose(text3);
	fclose(text4);
	fclose(out);
	fclose(out2);
	fclose(out3);
	fclose(out4);
	fclose(stopwords);
    //freeList( &root );
    return 0;
}

char specialarray[47];					/*global array because i needed to use it across functions*/

int specialchar1() {							/*tokenizes special characters into character array*/
	spec = fopen("specialcharacters.txt", "r");
	
	char specialcount;
	int k=0;
	
	while((fscanf(spec,"%c",&specialcount))!= EOF) {			/*creates an array populated by the 47 special characters*/
		fscanf(spec,"%c",&specialarray[k]);
		fprintf(test, "%c\n", specialarray[k]);
		k++;
	}
	
	fclose(spec);
	return 0;
	
}

int specialchar2(randomarray) {						/*compares an element in the array to the 47 special characters*/
	for (int k =0; k<47; k++) {
		if(randomarray = specialarray[k]) {
			specdetected = 1;
			return;
		}
	}
	return 0;
}

/*
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
*/