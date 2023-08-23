#include "process_shell.h"

/**
 * process_loc - Entry point of the process
 * @cmd: command
 *
 * Return: 0 on success
 */
char *process_loc(char *cmd)
{
	char *path, *path_cpy, *path_tkn, *file_p;
	int cmd_length, dir_length;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		path_cpy = strdup(path);
		cmd_length = strlen(cmd);
		path_tkn = strtok(path_cpy, ":");
		while (path_tkn != NULL)
		{
			dir_length = strlen(path_tkn);
			file_p = malloc(cmd_length + dir_length + 2);
			if (!file_p)
			{
				free(path_cpy);
				return (NULL);
			}
			strcpy(file_p, path_tkn);
			strcat(file_p, "/");
			strcat(file_p, cmd);
			strcat(file_p, "\0");
			if (stat(file_p, &buffer) == 0)
			{
				free(path_cpy);
				return (file_p);
			}
			else
			{
				free(file_p);
				path_tkn = strtok(NULL, ":");
			}
		}
		free(path_cpy);
		if (stat(cmd, &buffer) == 0)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}
