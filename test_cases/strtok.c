#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "Jay you got this";
	char *delim = " ";
	char *token;

	token = strtok(str, delim);

	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	return (0);
}
