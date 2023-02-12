#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/queue.h>
#include "main.h"
#include "_stack_.h"


char *util(char *token, char *op1, char *op2);
/**
 * eval_postfix - evaluate the given postfix expression.
 * @postfix: an array of strings representing the postfix expression.
 * @ht: pointer to a hash map.
 * Return: string representing the answer to the postfix expression.
*/
char *eval_postfix(char **postfix, hash_table_t *ht)
{
	head_t stack;
	char *operand1, *operand2;
	char *answer;
	char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i = 0;

	SLIST_INIT(&stack);
	(void) ht;

	while (postfix[i])
	{
		if (strstr(upper, postfix[i]))
		{
			push(&stack, postfix[i]);
		} else if (strcmp(postfix[i], "not") == 0)
		{
			operand1 = pop(&stack);
			answer = strcmp(operand1, "T") == 0 ? "F" : "T";
			push(&stack, answer);
		} else
		{
			operand2 = pop(&stack);
			operand1 = pop(&stack);
			answer = util(postfix[i], operand1, operand2);
			push(&stack, answer);
		}
		i++;
	}
	return (pop(&stack));
}

/**
 * util - evaluates boolean expression.
 * @token: string representing a particular operator.
 * @op1: first operand.
 * @op2: second operand.
 * Return: result of the expression.
*/
char *util(char *token, char *op1, char *op2)
{
	char *str = NULL;

	if (strcmp(token, "and") == 0)
	{
		if (strcmp(op1, "T") == 0 && strcmp(op2, "T") == 0)
		{
			str = "T";
		} else
		{
			str = "F";
		}
	} else if (strcmp(token, "or") == 0)
	{
		if (strcmp(op1, "F") == 0 && strcmp(op2, "F") == 0)
		{
			str = "F";
		} else
		{
			str = "T";
		}
	} else if (strcmp(token, "==") == 0)
	{
		str = strcmp(op1, op2) == 0 ? "T" : "F";
	}
	return (str);
}
