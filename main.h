#ifndef HEADER_FILE
#define HEADER_FILE

#include "_hash_.h"

char *eval_postfix(char **postfix, hash_table_t *ht);
char **infix_2_postfix(char **args);
char *read_line(void);
char **split_line(char *line);
void sh_loop(void);

#endif /* HEADER_FILE */
