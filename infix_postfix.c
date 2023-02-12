#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/queue.h>
#include "_hash_.h"
#include "main.h"
#include "_stack_.h"

#define TOK_BUFSIZE 64

/**
 * infix_2_postfix - convert an infix expression to a postfix expression.
 * @args: an array of strings representing the tokens making up an
 * infix expression.
 * Return: an array of strings representing the tokens making up a
 * postfix expression.
*/
char **infix_2_postfix(char **args)
{
	hash_table_t *ht;
	head_t stack;
	int bufsize = TOK_BUFSIZE;
	char **postfix = malloc(bufsize * sizeof(char *));
	char *token;
	char *prec;
	int position = 0;
	int i = 0;
	char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *numeric = "0123456789";

	if (!postfix)
	{
		fprintf(stderr, "Memory allocation failed!!!\n");
		exit(EXIT_FAILURE);
	}

	ht = hash_table_create(1024);
	SLIST_INIT(&stack);

	hash_table_set(ht, "*", "3");
	hash_table_set(ht, "/", "3");
	hash_table_set(ht, "+", "2");
	hash_table_set(ht, "-", "2");
	hash_table_set(ht, "(", "1");

	while (args[i])
	{
		if (strstr(upper, args[i]) || strstr(numeric, args[i]))
		{
			postfix[position] = args[i];
			position++;
		} else if (strcmp(args[i], "(") == 0)
		{
			push(&stack, args[i]);
		} else if (strcmp(args[i], ")") == 0)
		{
			token = pop(&stack);
			while (strcmp(token, "(") != 0)
			{
				postfix[position] = token;
				position++;
				token = pop(&stack);
			}
			free(token);
		} else
		{
			while (!SLIST_EMPTY(&stack))
			{
				token = hash_table_get(ht, SLIST_FIRST(&stack)->s);
				prec = hash_table_get(ht, args[i]);
				if (strcmp(token, prec) > 0 || strcmp(token, prec) == 0)
				{
					postfix[position] = pop(&stack);
					position++;
				}
				else
				{
					break;
				}

			}
			push(&stack, args[i]);
		}
		/* Allocate more memory if there is likely to be an overflow. */
		if (position >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			postfix = realloc(postfix, bufsize * sizeof(char *));
			if (!postfix)
			{
				fprintf(stderr, "Memory reallocation failure!!!\n");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	/* Append any operator still in the stack to the end of the array. */
	while (!SLIST_EMPTY(&stack))
	{
		postfix[position] = pop(&stack);
		position++;
		if (position >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			postfix = realloc(postfix, bufsize * sizeof(char *));
			if (!postfix)
			{
				fprintf(stderr, "Memory reallocation failure!!!\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	hash_table_delete(ht);
	postfix[position] = NULL;
	return (postfix);
}
