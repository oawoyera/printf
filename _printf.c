#include "main.h"
int _print_num(int, int);
int _print_bin(unsigned int num, int count);
int _print_unsigned_num(unsigned int num, int count);
int _print_octal(unsigned int num, int count);
int _print_hex(unsigned long int num, int count, int flag);
/**
 * _printf - prints formatted arguments passed
 * @format: pointer to format specifiers
 * Return: If Success- number of characters printed to stdout otherwise -1
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, count = 0; /*flag_index = 0, j;*/
	char *string; /*flag;*/

	/*flag = "+ #lh0123456789.-";*/
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] != '%')
			_putchar(format[i]), count++;
		if (format[i] == '%')
		{
		i++;
		if (format[i] == '\0')
			return (-1);
		/**
		* while (format[i]) == '+' || format[i] == ' ' || format[i] == '#')
		*{
		*	if (flag_index = 0)
		*		j = i;
		*	flag_index++;
		*	i++;
		*}
		*/
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
		case 'd':
			count = _print_num(va_arg(ap, int), count);
			break;
		case 'i':
			count = _print_num(va_arg(ap, int), count);
			break;
		case 'b':
			count = _print_bin(va_arg(ap, unsigned int), count);
			break;
		case 'u':
			count = _print_unsigned_num(va_arg(ap, unsigned int), count);
			break;
		case 'o':
			count = _print_octal(va_arg(ap, unsigned int), count);
			break;
		case 'x':
			count = _print_hex(va_arg(ap, unsigned int), count, 0);
			break;
		case 'X':
			count = _print_hex(va_arg(ap, unsigned int), count, 1);
			break;
		case 'S':
			string = va_arg(ap, char*);
			if (string == NULL)
				string = "(null)";
			while (*string)
			{
				if (((*string > 0) && (*string < 32)) || (*string >= 127))
					if (*string < 16)
						_printf("\\x0%X", *string++);
					else
						_printf("\\x%X", *string++);
				else
					_putchar(*string++), count++;
			}
			break;
		case 'p':
			_putchar('0'), count++;
			_putchar('x'), count++;
			count = _print_hex((unsigned long int)va_arg(ap, void*), count, 0);
			break;
		default:
			_putchar('%'), count++;
			_putchar(format[i]), count++;
		}
		}
		i++;
	}
	_putchar(-1);
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
	int j = 0, temp, neg = 0, min = 0;
	char *tmp_str;

	temp = num;
	if (temp < 0)
	{
		if (temp == 0 - 2147483648)
		{
			temp = 0 - 2147483648 + 1;
			min = 1;
		}
		num = temp =  0 - temp, neg = 1;
	}
	while (temp > 9)
		temp /= 10, ++j;
	++j;
	tmp_str = malloc((j + 1) * sizeof(char));
	if (tmp_str == NULL)
		exit(-1);
	tmp_str[j] = '\0';
	if (min == 1)
	{
	tmp_str[--j] = (num % 10) + 1 + '0';
	num /= 10;
	}
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
/**
 * _print_bin - converts an unsigned int to binary and prints to stdout
 * @num: the unsigned int
 * @count: counts number of characters printed
 *
 * Return: number of characters printed
 */
int _print_bin(unsigned int num, int count)
{
	unsigned int i = 0, temp;
	char *tmp_bin;

	if (num == 0)
	{
		_putchar('0'), count++;
	}
	temp = num;
	while (num)
	{
		num /= 2;
		++i;
	}
	tmp_bin = malloc((i + 1) * sizeof(char));
	if (tmp_bin == NULL)
		exit(-1);
	tmp_bin[i] = '\0';
	while (i)
	{
		tmp_bin[--i] = (temp % 2) + '0';
		temp /= 2;
	}
	while (*tmp_bin)
		_putchar(*tmp_bin++), count++;
	return (count);
}
/**
 * _print_unsigned_num - print a decimal number to stdout
 * @num: the number to print
 * @count: number of characters printed
 *
 * Return: void
 */
int _print_unsigned_num(unsigned int num, int count)
{
	unsigned int j = 0, temp;
	char *tmp_str;

	temp = num;
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
	while (*tmp_str)
		_putchar(*tmp_str++), count++;
	return (count);
}
/**
 * _print_octal - converts an unsigned int to octal and prints to stdout
 * @num: the unsigned int
 * @count: counts number of characters printed
 *
 * Return: number of characters printed
 */
int _print_octal(unsigned int num, int count)
{
	unsigned int i = 0, temp;
	char *tmp_oct;

	if (num == 0)
	{
		_putchar('0'), count++;
	}
	temp = num;
	while (num)
	{
		num /= 8;
		++i;
	}
	tmp_oct = malloc((i + 1) * sizeof(char));
	if (tmp_oct == NULL)
		exit(-1);
	tmp_oct[i] = '\0';
	while (i)
	{
		tmp_oct[--i] = (temp % 8) + '0';
		temp /= 8;
	}
	while (*tmp_oct)
		_putchar(*tmp_oct++), count++;
	return (count);
}
/**
 * _print_hex - converts an unsigned int to hexadecimal and prints to stdout
 * @num: the unsigned int
 * @count: counts number of characters printed
 * @flag: 0 if lower and 1 if upper
 *
 * Return: number of characters printed
 */
int _print_hex(unsigned long int num, int count, int flag)
{
	unsigned long int i = 0, temp;
	char *tmp_hex;
	char *hex_num;

	hex_num = "abcdefABCDEF";
	if (num == 0)
	{
		_putchar('0'), count++;
	}
	temp = num;
	while (num)
	{
		num /= 16;
		++i;
	}
	tmp_hex = malloc((i + 1) * sizeof(char));
	if (tmp_hex == NULL)
		exit(-1);
	tmp_hex[i] = '\0';
	while (i)
	{
		if ((temp % 16) > 9)
		{
			if (flag == 0)
				tmp_hex[--i] = hex_num[(temp % 16) - 10];
			else
				tmp_hex[--i] = hex_num[(temp % 16) - 10 + 6];
		}
		else
		{
			tmp_hex[--i] = (temp % 16) + '0';
		}
		temp /= 16;
	}
	while (*tmp_hex)
		_putchar(*tmp_hex++), count++;
	return (count);
}
