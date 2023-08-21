#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[])
{
	int i = 0;
	(void)argc;
	(void)argv;
	char *env_variable = envp[i];
	char *token = NULL;
	char *value = NULL;
	char *delim = "=";

	while (env_variable != NULL)
	{
		token = strtok(env_variable, delim);
		value = strtok(NULL, delim);
		if (strcmp(token, "API_KEY") == 0)
		{
			printf("API_KEY value is %s\n\n", value);
		}
		/* printf("%s\n", env_variable); */
		i++;
		env_variable = envp[i];
	}
	return (0);
}
