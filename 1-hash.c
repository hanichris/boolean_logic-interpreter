#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_hash_.h"

/**
 * hash_table_set - adds a new element of the hash table.
 * @ht: pointer to the hash table.
 * @key: key element to index the hash table.
 * @value: value element to store at the given key.
 * Return: 1 if successful. Otherwise, 0.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *curr;
	unsigned long int index;
	char *value_duplicate;

	if (!ht || !key)
		return (0);
	index = key_index((unsigned char *)key, ht->size);
	value_duplicate = strdup(value);

	/*Update value if the key is present within the hash table.*/
	if (ht->array[index])
	{
		for (curr = ht->array[index]; curr; curr = curr->next)
		{
			if (strcmp(curr->key, key) == 0)
			{
				free(curr->value);
				curr->value = value_duplicate;
				return (1);
			}
		}
	}
	/*Add key:value pair to the hash_table.*/
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
	{
		free(value_duplicate);
		return (0);
	}
	new_node->key = strdup(key);
	new_node->value = value_duplicate;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}

/**
 * hash_table_get - retrieve a value associated with a key.
 * @ht: pointer to the hash table.
 * @key: key whose value is to be retrieved.
 * Return: NULL or value at the given key.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	hash_node_t *curr;

	if (!ht || !key)
		return (NULL);
	index = key_index((unsigned char *)key, ht->size);
	if (ht->array[index])
	{
		for (curr = ht->array[index]; curr; curr = curr->next)
		{
			if (strcmp(curr->key, key) == 0)
			{
				return (curr->value);
			}
		}
	}
	return (NULL);
}

/**
 * hash_table_print - print out the hash table.
 * @ht: pointer to the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	char flag = 0;
	hash_node_t *curr;

	if (!ht)
		return;
	printf("{");
	for (i = 0; ht && i < ht->size; i++)
	{
		if (ht->array[i])
		{
			if (flag)
				printf(", ");
			for (curr = ht->array[i]; curr;)
			{
				printf("'%s': '%s'", curr->key, curr->value);
				curr = curr->next;
				if (curr)
					printf(", ");
			}
			flag = 1;
		}
	}
	printf("}\n");
}

/**
 * hash_table_delete - delete the hash table.
 * @ht: pointer to the hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *next, *curr;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
	{
		next = NULL;
		for (curr = ht->array[i]; curr; curr = next)
		{
			next = curr->next;
			free(curr->key);
			free(curr->value);
			free(curr);
		}
	}
	free(ht->array);
	free(ht);
	ht = NULL;
}
