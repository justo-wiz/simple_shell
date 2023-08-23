#include "process_shell.h"

/**
 * _reverse - to reverse characters
 * @str: string to reverse
 * @len: length of string.
 *
 * Return: void.
 */
void _reverse(char str[], int len)
{
	int start = 0;
	int end = len - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start] =  str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
/**
 * int_to_str - changes an integer to a string
 * @x: unsigned integer.
 * @str: string representation to store in.
 * @w: width of array.
 *
 * Return: converted integer.
 */
int int_to_str(unsigned int x, char str[], int w)
{
	int index = 0;

	while (x)
	{
		str[index++] = (x / 10) + '0';
		x = x / 10;
	}
	while (index < w)
	{
		str[index++] = '0';
	}
	_reverse(str, index);
	str[index] = '\0';
	return (index);
}
/**
 * _write - writes to std output.
 * @num: the value to write.
 *
 * Return: void
 */
void _write(unsigned int num)
{
	char new_str[30];
	char new_line = '\n';
	int length = int_to_str(num, new_str, 0);

	write(STDOUT_FILENO, new_str, length);
	write(STDOUT_FILENO, &new_line, 1);
}
