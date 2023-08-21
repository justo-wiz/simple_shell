#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	int var;
	char *av[] = {"/bin/ls", "-l", ".", "-a",  NULL};
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork failed\n)");
		return (-1);
	}
	if (child_pid == 0)
	{
		var = execve(av[0], av, NULL);
		if (var == -1)
			perror("Error\n");
	}
	else
	{
		wait(NULL);
		printf("Done with the execve av example\n");
		printf("Child PID is %u\n", child_pid);
	}	
	return (0);
}
