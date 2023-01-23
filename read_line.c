#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_line - reads in user input from the keyboard until
 * EOF or a newline is entered.
 * Return: buffer that was written to. Stores the string
 * obtained from the stdin.
*/
char *read_line(void)
{
	char *line = NULL;
	size_t linecapp = 0;

	if (getline(&line, &linecapp, stdin) == -1)
	{
		/* Check if the end-of-file is reached. */
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		/* Otherwise, print out the error that caused `getline` to fail. */
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
