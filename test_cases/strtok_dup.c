#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	char *delim = " \n";
	char *token;
	char *command;
	size_t size = 0;

	printf("$ ");
	if (getline(&command, &size, stdin) == -1)
		return (-1);

	token = strtok(command, delim);

	while (token)
	{
		printf("%s", token);
		token = strtok(NULL, delim);
	}
	printf("\n");
	free(command);
	free(token);
	return (0);
}
