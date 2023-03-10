#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

/**
 * split_line - splits the string passed to the function using the
 * defined delimiters above.
 * @line: pointer to a character array.
 * Return: A character array consisting of the words that made up
 * the string passed to the function.
*/
char **split_line(char *line)
{
	int bufsize = TOK_BUFSIZE;
	int position = 0;
	/* Allocate memory to store the words post split of `string`.*/
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Memory allocation error!!!\n");
		exit(EXIT_FAILURE);
	}

	/* Return first token from the `string`. */
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		/* Reallocate more memory space to hold the words if need be. */
		if (position >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Memory reallocation error!!!\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}

	/* Append `NULL` to demarcate end of array.*/
	tokens[position] = NULL;
	return (tokens);
}
