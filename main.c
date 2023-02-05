#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point.
 * @argc: Number of command line arguments passed to the function.
 * @argv: NULL terminated array of strings holding command line args.
 * Return: Exit_success.
*/
int main(int __attribute__ ((unused)) argc, char **argv)
{
	(void)argv;
    /* Initialize: Load config files if any. */

    /* Interpret: Run command loop */
	sh_loop();

    /* Terminate: Perform any shutdown/cleanup */
	return (EXIT_SUCCESS);
}
