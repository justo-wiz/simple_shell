#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *cmd = NULL, *cmd_cpy = NULL, *token = NULL;
	char *delim = " \n";
	size_t n = 0;
	int argc = 0, i = 0;
	char **argv = NULL;
	ssize_t read_line;
	int num_children = 5;
	int child_loop;

	while (1) {


		printf("$ ");
		read_line = getline(&cmd, &n, stdin);
		if (read_line == -1)
		{
			if (feof(stdin))
			{
				printf("\nEnd of File...Exiting\n");
				return (-1);
			}
			else
			{
				perror("Input Error\n");
				return (-1);
			}
		}
		for (child_loop = 0; child_loop < num_children; child_loop++)
		{
			pid_t child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error\n");
				return (-1);
			}
			else if (child_pid == 0)
			{
				char *args[] = {"ls", "-l", "/tmp", NULL};
				execve("/bin/ls", args, NULL);
				perror("execve");
			}
			else
			{
				pid_t parent_pid = getpid();
				int status;
				wait(&status);
				printf("Child PID is %u\n", child_pid);
				printf("Parent PID is %u\n", parent_pid);
				printf("Child process %d exited\n", child_loop + 1);
			}
		}
		cmd_cpy = strdup(cmd);

		token = strtok(cmd, delim);
		while (token)
		{
			token = strtok(NULL, delim);
			argc++;
		}

		argv = malloc(sizeof(char *) * argc);

		token = strtok(cmd_cpy, delim);
		while (token)
		{
			argv[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		argv[i] = NULL;

		i = 0;
		while (argv[i])
		{
			printf("%s\n", argv[i++]);
			execve("/tmp", argv, NULL);
			perror("execve\n");
		}
	}
	free(cmd), free(cmd_cpy), free(argv);

	return (0);
}
