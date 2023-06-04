#include "main.h"
int _print_num(int, int);
/**
 * _printf - prints formatted arguments passed
 * @format: pointer to format specifiers
 * Return: If Success- number of characters printed to stdout otherwise -1
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, count = 0;
	char *string;

	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] != '%')
			_putchar(format[i]), count++;
		if (format[i] == '%')
		{
		i++;
		if (format[i] == '\0')
		{
			_putchar('%'), count++;
			break;
		}
		switch (format[i])
		{
		case 'c':
			_putchar(va_arg(ap, int)), count++;
			break;
		case 's':
			string = va_arg(ap, char*);
			if (string == NULL)
				string = "(null)";
			while (*string)
				_putchar(*string++), count++;
			break;
		case '%':
			_putchar('%'), count++;
			break;
		default:
			_putchar('%'), count++;
			_putchar(format[i]), count++;
		}
		}
		i++;
	}
	va_end(ap);
	return (count);
}

/**
 * _print_num - print a decimal number to stdout
 * @num: the number to print
 * @count: number of characters printed
 *
 * Return: void
 */
int _print_num(int num, int count)
{
	int j = 0, temp, neg = 0;
	char *tmp_str;

	temp = num;
	if (temp < 0)
		num = temp =  0 - temp, neg = 1;
	while (temp > 9)
		temp /= 10, ++j;
	++j;
	tmp_str = malloc((j + 1) * sizeof(char));
	if (tmp_str == NULL)
		exit(-1);
	tmp_str[j] = '\0';
	while (j)
	{
		tmp_str[--j] = (num % 10) + '0';
		num /= 10;
	}
	if (neg == 1)
		_putchar('-'), count++;
	while (*tmp_str)
		_putchar(*tmp_str++), count++;
	return (count);
}
