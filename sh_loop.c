#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * sh_loop - REPL for the boolean logic interpreter
*/
void sh_loop(void)
{
	hash_table_t *ht;
	char *ans;
	char *line;
	char **result;
	char **args;
	int status = 1;

	ht = hash_table_create(1024);

	do {
		write(STDOUT_FILENO, "ʕ•́ᴥ•̀ʔっ ", 22);

		line = read_line();
		args = split_line(line);
		result = infix_2_postfix(args);
		ans = eval_postfix(result, ht);
		ans = hash_table_get(ht, ans) != NULL ? hash_table_get(ht, ans) : ans;
		
		ans = strcmp(ans, "T") == 0 ? "true" : "false";
		
		printf("Answer: %s\n\n", ans);

		free(result);
		free(args);
		free(line);
	} while (status);

	hash_table_delete(ht);
}
