#include "process_shell.h"
/**
 * _getenv - gets the enviroment
 * @name: name of the environmental variable
 * Return: returns NULL
 */

char *_getenv(const char *name)
{

	int a = 0;
	char *tkn;
	char *encpy;

	while (environ[a])
	{
		encpy = strdup(environ[a]);
		tkn = strtok(encpy, "=");
		if (strcmp(tkn, name) == 0)
			return (strtok(NULL, "="));
	/*	free(encpy);*/
		a++;
	}

	return (NULL);
}
