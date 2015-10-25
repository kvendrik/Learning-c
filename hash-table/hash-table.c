#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int size;
	char *keys[3];
	char *values[3];
} Hash;

Hash new_hash(int size){
	Hash hash;
	hash.size = size;
	//hash.keys = malloc(size);
	//hash.values = malloc(size);
	return hash;
}

Hash hash_add_pair(Hash hash, char key[], char value[], int idx){
	hash.keys[idx] = malloc(strlen(key)+1);
	strcpy(hash.keys[idx], key);

	hash.values[idx] = malloc(strlen(value)+1);
	strcpy(hash.values[idx], value);

	return hash;
}

Hash hash_set(Hash hash, char key[], char value[]){
	int key_idx = -1;
	int last_free_idx = -1;

	//check if key exists
	for(int i = 0; i < hash.size; i++){
		char *curr = hash.keys[i];
		if(curr == NULL){
			last_free_idx = i;
		} else if(curr == key){
			key_idx = i;
		}
	}

	if(key_idx > -1){
		//key already exists
		return hash_add_pair(hash, key, value, key_idx);
	} else if(last_free_idx > -1) {
		//else: add
		return hash_add_pair(hash, key, value, last_free_idx);
	} else {
		return hash;
	}
}

char *hash_get(Hash hash, char key[]){
	for(int i = 0; i < hash.size; i++){
		
		printf("%s\n", hash.keys[i]);
		printf("%s\n", hash.values[i]);
		
		if(hash.keys[i] == key){
			printf("%s\n", "Found");
			return hash.values[i];
		}
	}

	return "";
}


int main(int argc, char *argv[]){
	Hash hash = new_hash(1);
	hash = hash_set(hash, "age", "20");

	printf("%s\n", hash_get(hash, "age"));
}