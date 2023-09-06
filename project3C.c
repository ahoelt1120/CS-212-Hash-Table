# include "project3C_hashtable.h"

int main(){
	// Prompts user to enter a file name or leave blank to exit
	char input[50];
	FILE *f = NULL;
	while (f == NULL){
	printf("Enter the filename (or leave blank to quit): ");
	fgets(input, sizeof(char)*50, stdin);
	if(input[0] == '\n'){
		printf("No file entered, exiting program...\n");
		exit(0);
	}

	// Replace newline character with the void character
	
	for (int i = 0; i < 50; i++){
		if(input[i] == '\n'){
			input[i] = '\0';
			break;
		}
	}	

	// Attempting to open the file

	f = fopen(input, "r");
	if (f == NULL) {
		printf("Failed to open file \'%s\'. Please try again.\n", input);
		
	}
	}
	printf("Tokenizing file \'%s\' and building hash bucket...", input);

	// Tokenizing file and building the hash bucket

	HashTable *ht = malloc(sizeof(HashTable));
	initialize(ht);
	
	char str[100];
	char *token;
	int line_num = 1;
	
	do {
		fgets(str, 101, f);
		
		if (str[0] != '\n'){	
		str[strcspn(str, "\n")] = '\0';
		
		token = strtok(str, " ");
		while (token != NULL) {
			char *lower = token;
			int length = strlen(token);	
			for (int i = 0; i < length; i++){
				lower[i] = tolower(lower[i]);
				if(lower[i] == '\n'){
					lower[i] = '\0';
				}
			}
					
			
		
			insert(ht, lower, line_num);	
			token = strtok(NULL, " ");
			
		}
		line_num++;
		}
	}while(!feof(f));
	printf("done.\n");
	printf("Load factor: %.2f\n", calculateLoadFactor(ht));
	fclose(f);
	
	
	// Searching for the word
	int count = 0;
	char key[50];
	printf("Enter a word to search (or leave blank to quit): ");
	fgets(key, sizeof(char)*50, stdin);
	while(key[0] != '\n'){
	int *results = NULL;
	for (int i = 0; i < 50; i++){
		if(key[i] == '\n'){
			key[i] = '\0';
			break;
		}
	}
	int length = strlen(key);
	for (int i = 0; i < length; i++){
		key[i] = tolower(key[i]);
	}
	
	get(ht, key, &results, &count);

	
	// Print results of the search for a word
	if(count != 0){
	printf("Word \'%s\' found at line number(s): ", key);
	for (int i =0; i < count; i++){
		printf("%d ", results[i]);
	
	}
	printf("\n");


	
	
	

	}else{
		printf("Word \'%s\' not found.\n", key);
	}
	free(results);

	

	printf("Enter a word to search (or leave blank to quit): ");
	fgets(key, sizeof(char)*50, stdin);

	}
	
	
	// Freeing all dynamic memory used by the hash table

	freeHashTable(ht);


}
