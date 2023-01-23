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
	int status = 1;

	do {
		write(STDOUT_FILENO, "ʕ•́ᴥ•̀ʔっ ", 22);
		line = read_line();
		printf("%s", line);
		free(line);
	} while (status);

}
