#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
	char *env_variable = getenv("API_KEY");
	if (env_variable == NULL)
	{
		printf("Environmental variable not found\n");
		return (1);
	}
	printf("The Environmental variable is %s\n", env_variable);
	return (0);
}
