#include "process_shell.h"
/**
 * _getenv - Entry point
 * @name: name of the environ variable
 * Return: returing NULL
 */

char *_getenv(const char *name)
{
	char **environ;
	int a = 0;
	char *tkn;

	while (environ[a])
	{
		tkn = strtok(environ[a], "=");
		if (strcmp(tkn, name) == 0)
			return (strtok(NULL, "="));
		a++;
	}
	return (NULL);
}
