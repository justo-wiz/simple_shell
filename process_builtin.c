#include "process_shell.h"
/**
 * builtin_cmd - inbuilt commands
 * @args: input
 * @env: environmental variable
 * Return: 0 Always
 */
int builtin_cmd(char **args, char **env)
{
	if (strcmp(args[0], "exit") == 0)
	{
		_printst("\n");
		free_args(args);
		exit(98);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			chdir(_getenv("HOME"));
		}
		else
		{
			if (chdir(args[1]) != 0)
			{
				perror("Error: invalid command");
			}
		}
		free_args(args);
		return (1);
	}
	if (strcmp(args[0], "env") == 0)
	{
		_env(env);
		free_args(args);
		return (1);
	}
	return (0);
}
/**
 * _env - Entry point
 * @env: environment variable
 */
void _env(char **env)
{
	int i = 0;

	while (env[i])
	{
		_printst(env[i]);
		_printst("\n");
		i++;
	}
}
