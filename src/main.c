#include <stdio.h>
#include "../include/linkedList.h"

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
