#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node
{
	char *key;
	int value;
	struct Node *next;

} Node;

#define BUCKET_SIZE 100
typedef struct hash {
	Node *bucket[BUCKET_SIZE];
	int count; // Number of elements (linked list nodes) in the hash table


} HashTable;

unsigned int hash(const char *key);
void initialize(HashTable *ht);
Node *createNode(const char *key, int value);
void insert(HashTable *ht, const char *key, int value);
void get(HashTable *ht, const char *key, int **results, int *count);
void freeHashTable (HashTable *ht);
float calculateLoadFactor(HashTable  *ht);




#endif
