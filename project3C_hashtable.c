# include "project3C_hashtable.h"

// Create hash (this code was provided by the instructor)

unsigned int hash(const char *key)
{
	unsigned int hash = 0;
	for (int i = 0; key[i] != '\0'; i++)
	{
		hash = hash * 31 + key[i];
	}

	return hash % BUCKET_SIZE;

}

// Creating a node with a key and a value

Node *createNode(const char *key, int value){

	Node *new_node = (Node *)malloc(sizeof(Node));
	if (new_node == NULL){
		printf("Failed to allocate memory for new node.");
		exit(0);
	}
	new_node->key = strdup(key);
	new_node->value = value;
	new_node->next = NULL;

	
	return new_node;

}

// Initializing the hash table

void initialize(HashTable *ht){
	ht->count = 0;
	for(int i = 0; i < BUCKET_SIZE; i++){
		ht->bucket[i] = NULL;
	}

}

// Inserting a key value pair into a hash table


void insert(HashTable *ht, const char *key, int value){
	Node *new_node = createNode(key, value);
	unsigned int cur_hash = hash(key);
	
		
	if (ht->bucket[cur_hash] != NULL){
		
		Node *cur_addr = ht->bucket[cur_hash];
		
		while (cur_addr->next != NULL){
			
			cur_addr = cur_addr->next;
		}
		
		cur_addr->next = new_node;
		//printf("key and hash: %d %s\n", cur_hash, cur_addr->next->key);
		
	
		
	}else{
		ht->bucket[cur_hash] = new_node;
	//printf("key and hash: %d %s\n", cur_hash, ht->bucket[cur_hash]->key);	
	
	}
	ht->count++;
	
		


}

// Get value from the hash table

void get(HashTable *ht, const char *key, int **results, int *count){
	unsigned int hash_num = hash(key);
	

	int num = 0;
	
	if (ht->bucket[hash_num] != NULL){
		Node *cur_node = ht->bucket[hash_num];
		*results = (int *)malloc(sizeof(int)*BUCKET_SIZE);	
		
		
		while (cur_node != NULL){	
			if(strcmp(cur_node->key, key) == 0){
				
			(*results)[num] = cur_node->value;
				
			num++;
			}
			cur_node = cur_node->next;
			
		}
		

		}
		
		
	
	
	*count = num;


}

// Free all dynamic memory used by hash table

void freeHashTable(HashTable *ht){
	
	for(int i = 0; i < BUCKET_SIZE; i++){
		if(ht->bucket[i] != NULL){	
			Node *cur_node = ht->bucket[i];
			while(cur_node->next != NULL){
				Node *tmp = cur_node;
				cur_node = cur_node->next;
				free(tmp->key);	
				free(tmp);
			
			}
			free(cur_node->key);
			free(cur_node);
			
		
		}
		}
			
	free(ht);	


}

// Calculates the load factor of the hash table

float calculateLoadFactor(HashTable *ht){
	
	//float count = (float)ht->count;		
	float load_factor = (float)ht->count / BUCKET_SIZE;
	
	return load_factor;

}




