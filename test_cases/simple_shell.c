#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
	char *command = NULL;
	size_t size = 0;
	ssize_t read_line;
	char *token = NULL;
	int status;
	pid_t child_pid;
	int mode = isatty(0);

	while(1)
	{
		if (mode == 1)
		{
			printf("$ ");
			read_line = getline(&command, &size, stdin);

			if(read_line == -1)
			{
				if (feof(stdin))
				{
					printf("\nEnd of File..Exiting\n");
					return (EXIT_FAILURE);
				}
				else
				{
					perror("Error\n");
					return (EXIT_FAILURE);
				}
			}
			token = strtok(command, " \n");

			if (token != NULL)
			{
				child_pid = fork();
				if (child_pid == -1)
				{
					perror("Error\n");
					exit(EXIT_FAILURE);
				}
				else if (child_pid == 0)
				{
					char *args[] = {token, NULL};
					execve(token, args, NULL);
					perror("execve");
					exit(EXIT_FAILURE);
				}
				else
				{
					wait(&status);
				}
			}
		}
	}
	free(command);

	return (0);
}
