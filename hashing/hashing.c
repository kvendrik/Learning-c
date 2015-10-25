#include <stdio.h>
#include <string.h>

int getCharIdx(char character){
	char chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz<>@!#$%^&*()_+[]{}?:;|'\"\\,./~`-=";
	int charIdx = strchr(chars, character)-chars;

	if(charIdx > 0) {
    	return charIdx;
	}

	return -1;
}

int getCharType(char character){
	char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char numbers[] = "0123456789";
	char specials[] = "<>@!#$%^&*()_+[]{}?:;|'\"\\,./~`-=";

	int charIdx = strchr(chars, character)-chars;
	if(charIdx > 0) {
    	return 0;
	}

	charIdx = strchr(numbers, character)-numbers;
	if(charIdx > 0) {
    	return 1;
	}

	charIdx = strchr(specials, character)-specials;
	if(charIdx > 0) {
    	return 2;
	}

	return -1;
}

int main(int argc, char *argv[]){
	char *input = argv[1];

	int hashNumber = 0;

	int charIndexTotal = 0;
	int salt1Total = 0;

	int specialCharsCount = 0;
	int alphCharsCount = 0;
	int numbersCount = 0;

	for(int i = 0; i < strlen(input); i++){
		char curr = input[i];

		int charIdx = getCharIdx(curr);
		int charType = getCharType(curr);

		switch(charType){
			case 0:
				alphCharsCount++;
				break;
			case 1:
				numbersCount++;
				break;
			case 2:
				specialCharsCount++;
				break;
		}

		salt1Total += strlen(input) % charIdx;
		charIndexTotal += charIdx;
	}

	int y = charIndexTotal * 0.232;
	int key = (y % strlen(input));
	int salt2Total = (alphCharsCount ^ numbersCount ^ specialCharsCount);

	key = key >> salt2Total;

	printf("%i\n", key);
	printf("%i\n", salt1Total);
	printf("%i\n", key + salt1Total);

	printf("%i\n", alphCharsCount);
	printf("%i\n", numbersCount);
	printf("%i\n", specialCharsCount);
	printf("%i\n", salt2Total);
}