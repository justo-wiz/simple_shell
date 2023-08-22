#include "process_shell.h"

/**
 * handle_comment - handles comment.
 * @str: string inputed.
 * Return: nothing.
 */

void handle_comment(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '#')
			str[i] = '\0';
		i++;
	}
}
