#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_stack_.h"

/**
 * push - add an element to the top of the stack.
 * @head: pointer to the top of the stack.
 * @s: pointer to the character array to append to the stack.
*/
void push(head_t *head, const char *s)
{
	node_t *elem = NULL;

	elem = malloc(sizeof(node_t));
	if (!elem)
	{
		fprintf(stderr, "Node memory allocation error!!!\n");
		exit(EXIT_FAILURE);
	}

	elem->s = strdup(s);
	SLIST_INSERT_HEAD(head, elem, nodes);
}

/**
 * pop - retrieve the element at the top of the stack.
 * @head: pointer to the top of the stack.
 * Return: string that was at the top of the stack.
*/
char *pop(head_t *head)
{
	char *s;
	node_t *elem = NULL;

	if (SLIST_EMPTY(head))
	{
		printf("Can't pop an empty stack.\n");
		return (NULL);
	}

	elem = SLIST_FIRST(head);
	s = strdup(elem->s);
	SLIST_REMOVE_HEAD(head, nodes);
	free(elem->s);
	free(elem);
	return (s);
}

/**
 * free_stack - frees up the memory used to create the stack.
 * @head: pointer to the top of the stack.
*/
void free_stack(head_t *head)
{
	node_t *elem = NULL;

	if (SLIST_EMPTY(head))
	{
		printf("Stack is already empty.");
		exit(EXIT_SUCCESS);
	}

	while (!SLIST_EMPTY(head))
	{
		elem = SLIST_FIRST(head);
		SLIST_REMOVE_HEAD(head, nodes);
		free(elem->s);
		free(elem);
		elem = NULL;
	}
}
