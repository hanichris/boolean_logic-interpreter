#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * sh_loop - REPL for the boolean logic interpreter
*/
void sh_loop(void)
{
	hash_table_t *ht;
	char *line;
	char **result;
	char **args;
	int status = 1;

	do {
		write(STDOUT_FILENO, "ʕ•́ᴥ•̀ʔっ ", 22);
		int i = 0;

		line = read_line();
		args = split_line(line);
		result = infix_2_postfix(args);

		while (result[i])
		{
			printf("%s ", result[i]);
			i++;
		}
		printf("\n");


		free(result);
		free(args);
		free(line);
	} while (status);

}
