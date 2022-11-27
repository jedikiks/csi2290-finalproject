#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAYSIZE( array ) sizeof( array ) / sizeof( array[0] )

/*
struct Freq{
    char word[50];
    int numTimes;
};
*/

typedef struct Str
{
    double numTimes;
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

void getWords( FILE* file );
void printWords();
void makeLowercase();
void alphebetize();
void getFrequency();

//FILE* fp = NULL; 
Sqlist L;


int main()
{
	initSqlist(&L, 1000);     //Initialize str, the size is 1000, used to store the segmented words
	/*
	char f1[] = "d1.txt"; //file location (your d1-d4.txt file location 
	char f2[] = "d2.txt";
	char f3[] = "d3.txt"; 
	char f4[] = "d4.txt";
	*/

	FILE* d1 = fopen( "d1.txt", "r" );
	if( !d1 )
		perror( "couldnt open d1" );
	FILE* d2 = fopen( "d2.txt", "r" );
	if( !d2 )
		perror( "couldnt open d2" );
	FILE* d3 = fopen( "d3.txt", "r" );
	if( !d3 )
		perror( "couldnt open d3" );
	FILE* d4 = fopen( "d4.txt", "r" );
	if( !d4 )
		perror( "couldnt open d4" );

	getWords( d1 );
    /*
	getWords( d2 );
	getWords( d3 );
	getWords( d4 );
    */
	printWords();
    makeLowercase();
    alphebetize();
    getFrequency();
/*
	printwords(f1);
	printwords(f2);
	printwords(f3);
	printwords(f4);
*/	


    
	// print to stdout：
    /*
	for (int i = 0; i < L.length; i++)
	{
		fprintf( stdout, "word: %s, frequency: %d\n", L.data[i].word, L.data[i].numTimes );
	}
    */

	return 0;
}

void
printToFile( FILE* file ){
    if( file == NULL ){
	    fprintf( stderr, "Could not read from file" );
    } else{
	    for (int i = 0; i < L.length; i++)
	    {
	    	fprintf( file, "%s\n", L.data[i].word );
	    }
    }
}

void
getFrequency(){
    char currentWord[1028]; 
    int position = 0;
    int maxFreq = 0;

    /***********************
     * Find the frequencies
     *   of each element 
     ***********************/
	for (int i = 0; i < L.length; i++){
        for( int j = i; j < L.length; j++ ){
            if( strcmp( L.data[i].word, L.data[j].word ) == 0 ){
                L.data[i].numTimes++;
            } else{
                break;
            }
        }

        if ( L.data[i].numTimes > maxFreq ){
            maxFreq = L.data[i].numTimes;
        }
    }

    /***********************
     * Find the frequencies
     *     of each word
     ***********************/
    strcpy( currentWord, L.data[0].word );
    while( position < L.length ){
        if ( strcmp( currentWord, L.data[position].word ) == 0 ){
            position++;
        } else{
             //fprintf( stdout, "ith word[%d]: %s, jth word[%d]: %s\n", i, L.data[i].word, j, L.data[j].word );
             strcpy( currentWord, L.data[position].word );
             fprintf( stdout, "Word: %s \t\tFrequency: %f \t\tWeight: %f\n", currentWord, L.data[position].numTimes, ( L.data[position].numTimes / maxFreq ) );
        }
    }
}

/*
void
getFrequency( FILE* file ){
    struct Freq freq;
    char buffer[1028];

    if( file == NULL ){
	    fprintf( stderr, "Could not read from file" );
    } else{
        char currentWord[1028];
        fgets( buffer, 1028, currentWord );
        freq.word = currentWord;

        while( fgets( buffer, 1028, file ) != NULL ){
            if( strcmp( buffer, currentWord ) == 0 ){
                freq.numTimes++;
        }
    }

}
*/

/*for qsort() when ordering array alphabetically
more info on: https://iq.opengenus.org/qsort-in-c/
*/
int
compare(const void *a, const void *b) {
	const Str* wordA = a;
	const Str* wordB = b;
	return strcmp(wordA->word, wordB->word);
}

void 
alphebetize(){
	//alphabetize
	qsort(L.data, L.length, sizeof(*L.data), compare);

	//test：
    /*
	for (int i = 0; i < L.length; i++)
	{
		printf("%s\n", L.data[i].word);
	}
    */
}

void
makeLowercase(){
	/*it is important to convert all characters in the words to lowercase if necessary.
	 This will be important when computing for freq. and weight.
	 It will also matter when checking for stop words
	 ex:
	 "You'll" and "you'll" should be considered the same word
	*/
	for (int i = 0;i < L.length;i++) {
		for (int j = 0;j < strlen(L.data[i].word);j++) {
			char c = L.data[i].word[j];
			if ((c >= 'A') && (c <= 'Z')) {
				//add 32 to ASCII value of character
				L.data[i].word[j] = (char)((int)c + 32);
			}
		}
	}
}

void
getWords( FILE* file ){
	 
	char* word;
	char string[1024];
	char buffer[1024];
	char stopWord[1024];

	FILE* stopWordFile = fopen( "stopwords.txt", "r" );
	if( !stopWordFile ){
		fprintf( stderr, "Could not open stopwords.txt\n" );
	}

	if ( file == NULL){
		fprintf( stderr, "Could not read from file" );
	} else{
		while (fgets( buffer, ARRAYSIZE( buffer ) , file ) != NULL){
			strcpy( string, buffer ); 
			word = strtok( string, " " );								// its not a stop word 
			while( word != NULL ){											// Copy each word if
				if( strcmp( word, fgets( stopWord, ARRAYSIZE( stopWord ), stopWordFile ) ) != 0 ){	// into the array
						strcpy( L.data[L.length].word, word );
						L.length++;
				}
				word = strtok( NULL, " " );								// its not a stop word 
			}
		}
	}

	fclose( file );
}

void printWords(){
	for( int i = 0; i < L.length; i++ )
	{
		char* p = " `~1!2@3#4$$5%6^7&8*9()0-_=+[{]}\\|;:\',<.>/?¦©・";  //collection of delimiters
		char buf[1024] = { 0 };
		strcpy( buf, L.data[i].word );    //Copy to the buf array and operate on the buf array
		char* ret = NULL;
		for (ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))  //Use strtok for loop segmentation operation
		{
			//printf( "%s", ret );
			strcpy( L.data[i].word, ret );  //Store it in the str structure
		}
	}
}
