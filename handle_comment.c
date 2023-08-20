#include "process_shell.h"

/**
 * handle_comment - Entry point
 * @str: input
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
