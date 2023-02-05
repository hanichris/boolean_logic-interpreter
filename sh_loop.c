#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * sh_loop - REPL for the boolean logic interpreter
*/
void sh_loop(void)
{
	char *line;
	char **args;
	int status = 1;

	do {
		write(STDOUT_FILENO, "ʕ•́ᴥ•̀ʔっ ", 22);
		int i = 0;

		line = read_line();
		args = split_line(line);

		while (args[i])
		{
			printf(">>> %s\n", args[i]);
			i++;
		}

		free(args);
		free(line);
	} while (status);

}
