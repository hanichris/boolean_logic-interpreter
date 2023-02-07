#include <stdlib.h>
#include "_hash_.h"

/**
 * hash_table_create - create an empty hash table with Chaining
 * collision handling.
 * @size: size of the hash table array.
 * Return: Pointer to the created hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *head;
	unsigned long int i;

	head = malloc(sizeof(hash_table_t));
	if (!head)
		return (NULL);

	head->size = size;
	head->array = malloc(sizeof(hash_node_t *) * size);
	if (!head->array)
		return (NULL);
	for (i = 0; i < size; i++)
		head->array[i] = NULL;
	return (head);
}

/**
 * hash_djb2 - implementation of the djb2 algorithm.
 * @str: String whose hash is to be computed.
 * Return: hash value of the string.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return (hash);
}

/**
 * key_index - compute the index of a given key.
 * @key: string whose index in the array is to be determined.
 * @size: size of the array.
 * Return: the index of the key in the array.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	hash = hash_djb2((unsigned char *) key);
	return (hash % size);
}
