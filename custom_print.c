#include "process_shell.h"

/**
 * _putchar - Entry Point
 * @c: input
 * Return: c
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printst - Entry point
 * @str: string to print
 * Return: count
 */

int _printst(char *str)
{
	int i = 0, count = 0;

	while (str[i])
	{
		count += _putchar(str[i++]);
	}
	return (count);
}

