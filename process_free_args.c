#include "process_shell.h"
/**
 * free_args - frees an array of strings
 * @args: Array of strings
 * Return: Always void
 */

void free_args(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}

	free(args);
}
