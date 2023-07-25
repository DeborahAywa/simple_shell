#include "shell.h"

/**
 * _erratoi - function that converts a string to an integer
 *
 * @s:string to be converted
 * Return:if no numbers in string return 0 otherwise -1
 */
int _erratoi(char *s)
{
	unsigned long int res = 0;
	int i = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			res *= 10;
			res += (s[i] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * print_error - function that prints an error message
 *
 * @command: struct containing potential arguments
 * @estr:string containing specified error type
 *
 * Return:0 if no numbers in string or converted number
 * otherwise -1 on error
 */
void print_error(command_t *command, char *estr)
{
	_eputs(command->fname);
	_eputs(": ");
	print_d(command->line_count, STDERR_FILENO);
	_eputs(": ");
	_euts(command->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function that prints a decimal number base 10
 *
 * @input:the input
 * @fd:file descriptor to write to
 *
 * Return:number of characters to be printed
 */
int print_d(int input, int fd)
{
	int (*_putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs = _input;
		__putchar('-');
		count++;
	}
	else
		_abs = input;
	current  = _abs_;
	for (i = 1000000000; i > 1; 1 /= 10)
	{
		if (_abs_ / i)
		{
			_putchar('0' + current / i);
			count++;
			current %= i;
		}
		__putchar('0' + current);
		count++;
		return (count);
	}
}

/**
 * convert_number - converts a function of itoa
 *
 * @num:number
 * @base:base
 * @flags:argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWER ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = (&buffer[49]);
	*ptr = '\0';
	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0)
	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function that replaces first instances of #
 * with '\0'
 *
 * @buf:address of the string to modify
 * Return: Always return 0
 */
void remove_comments(char **buf)
{
	int j;

	for (j = 0; buf[j] != '\0'; j++)
		if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
		{
			buf[j] = '\0';
			break;
		}
}
