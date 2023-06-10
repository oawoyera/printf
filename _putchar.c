#include "main.h"
/**
 * _putchar - print a char to stdout
 * @c: the char
 *
 * Return: void
 */
void _putchar(char c)
{
	static char buf[1024];
	static int buf_count;

	if (buf_count == 1024)
	{
		write(1, buf, buf_count);
		buf_count = 0;
	}
	buf[buf_count] = c;
	buf_count++;
}
