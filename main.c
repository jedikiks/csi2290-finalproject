#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *text1, *text2, *text3, *text4;
	
	text1 = fopen("d1.txt", "r");
	text2 = fopen("d2.txt", "r");
	text2 = fopen("d3.txt", "r");
	text2 = fopen("d4.txt", "r");
	
	
	while((int c = getchar())!=EOF) {
		
	}
	
	
	/*this part would go in main after we were done reading from the original text files
	fclose(text1);
	fclose(text2);
	fclose(text3);
	fclose(text4);
	*/
}
