#include "shell.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}
int _getline(char *str)
{
	int count = 0, i = 0;

	while (str)
	{
		count = _putchar(str[i++]);
	}
	return (count);
}
