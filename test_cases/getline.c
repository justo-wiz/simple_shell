#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t n = 0;
	char *command = NULL;
	ssize_t read_line;

	printf("$ ");
	read_line = getline(&command, &n, stdin);

	if (read_line == -1)
	{
		if (feof(stdin))
		{
			printf("\nEnd of File...Exiting\n");
			return (-1);
		}
		else
		{
			perror("Error encountered\n");
			return (-1);
		}
	}
	printf("%scommand size is %ld\n", command, n);
	free(command);
	return (0);
}
