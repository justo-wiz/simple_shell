#include "process_shell.h"

/**
 * process_exe - Executes the commands
 * @args: arguments
 * @env: enviornmetal variable
 *
 * Return: void.
 */

void process_exe(char **args, char **env)
{
	char *cmd = NULL, *actual_path = NULL;
	pid_t id_child;
	int exeprocess, status;

	if (args)
	{
		if (builtin_cmd(args, env) == 1)
			return;
		cmd = args[0];
		/*call path*/
		actual_path = process_loc(cmd);

		id_child = fork();
		if (id_child < 0)
		{
			perror("Error, Fork Failed");
			free(cmd);
			exit(1);
		}
		else if (id_child == 0)
		{
			exeprocess = execve(actual_path, args, env);
			if (exeprocess == -1)
			{
				perror("Error: Command Failed!");
				free_args(args);
				exit(0);
			}
		}
		else
		{
			wait(&status);
		}
		free(cmd);
	}
}
