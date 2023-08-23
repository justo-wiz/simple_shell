#include "process_shell.h"

/**
 * _putchar - puts a character
 * @c: the character to input
 *
 * Return: returns the character c
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

