#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *text1, *text2, *text3, *text4;
	
	text1 = fopen("d1.txt", "r");
	text2 = fopen("d2.txt", "r");
	text2 = fopen("d3.txt", "r");
	text2 = fopen("d4.txt", "r");
	
	/*must decide on how best to read and tokenize the data*/
	while((int c = getchar())!=EOF) {
		
	}
	
	
	/*this part would go in main after we were done reading from the original text files*/
	fclose(text1);
	fclose(text2);
	fclose(text3);
	fclose(text4);
	
	/*copied from internet:
	
	syntax: char *strtok(char *str, const char *delim)

	Breaks string str into a series of tokens separated by delim.
	
	We might be able to delimit (separate) the strings read from our text files by setting the delimiter equal to spacebar
	
	I would also recommend visiting this link for ideas: https://www.tutorialspoint.com/c_standard_library/string_h.htm
	*/
}
