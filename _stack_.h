#ifndef _STACK_HEADER_
#define _STACK_HEADER_

#include <sys/queue.h>

/**
 * struct node - singly linked list representation of a stack.
 * @s: pointer to a character array.
 * @nodes: pointer to the nodes in the linked list.
 *
 * Description: Singly linked list node structure for stack,
 * LIFO.
*/
typedef struct node
{
	char *s;

	SLIST_ENTRY(node) nodes;
} node_t;

/* For ease of pointer assignment to `head_t` without compiler error. */
typedef SLIST_HEAD(stack, node) head_t;

void push(head_t *head, const char *s);
char *pop(head_t *head);
void free_stack(head_t *head);


#endif /* _STACK_HEADER_ */
