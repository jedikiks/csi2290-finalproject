#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAYSIZE( array ) sizeof( array ) / sizeof( array[0] )

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

FILE* fp = NULL; 
Sqlist L;

int main()
{
	initSqlist(&L, 1000);     //Initialize str, the size is 1000, used to store the segmented words
	char f1[] = "d1.txt"; //file location (your d1-d4.txt file location 
	char f2[] = "d2.txt";
	char f3[] = "d3.txt"; 
	char f4[] = "d4.txt";

/*
	printwords(f1);
	printwords(f2);
	printwords(f3);
	printwords(f4);
*/	
	//test：
	for (int i = 0; i < L.length; i++)
	{
		printf("%s\n", L.data[i].word);
	}

	return 0;
}

void
getWords( FILE* file ){
	 
	char* word;
	char string[1024];
	char buffer[1024];
	char stopWord[1024];

	FILE* stopWordFile = fopen( "stopWords.txt", "r" );
	fp = fopen( file, "r");
	
	if (fp == NULL){
		fprintf( stderr, "Could not read from file" );
	} else{
		while (fgets( buffer, ARRAYSIZE( buffer ) , fp) != NULL){
			strcpy( string, buffer ); 
			while( !word ){											// Copy each word if
				word = strtok( NULL, " " );								// its not a stop word 
				if( strcmp( word, fgets( stopWord, ARRAYSIZE( stopWord ), stopWordFile ) ) != 0 ){	// into the array
						strcpy( L.data[L.length].word, word );
						L.length++;
				}
			}
		}
	}
}

int printwords(fileofchoice) 
{
	char arr[1024] = {0};
	fp = fopen(fileofchoice, "r");
	if (fp == NULL)  //Determine whether reading the file is successful
	{
		printf("file read failed");
		return 1;
	}
	else
	{
		while (fgets(arr, 1013, fp) != NULL) //Read the content of each line in a loop, the first line of di.txt exceeds 1024bit, so it is read twice, and the others are divided once
		{
			char* p = " `~1!2@3#4$5%6^7&8*9(0)-_=+[{]}\\|;:',<.>/?¦©・";  //collection of delimiters
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
}
