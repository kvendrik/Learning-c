#include <stdio.h>
#include <string.h>

int getCharIdx(char character){
	char chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int charIdx = strchr(chars, character)-chars;
	return charIdx;
}

int main(int argc, char *argv[]){
	char *input = argv[1];
	float charIndexTotal = 0.0;

	for(int i = 0; i < strlen(input); i++){
		charIndexTotal += getCharIdx(input[i]);
	}

	printf("%f\n", charIndexTotal+0.5);
	printf("%lu\n", charIndexTotal % strlen(input));
}