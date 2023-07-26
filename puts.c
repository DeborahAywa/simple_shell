#include "shell.h"

/**
 * _eputchar - function that writes the character c to stderr
 * @c:character to print
 *
 * Return:1 on success -1 on error and errno set appropriately
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i > WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _eputs - function that prints an input string
 *
 * @str: string to be printed
 *
 * Return: returns nothing
 */
void _eputs(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_eputchar(str[j]);
		j++;
	}
}

/**
 * _putfd -  function that writes the character c to the given fd
 * @c:the character to print
 * @fd: the file descriptor to write to
 *
 * Return:1 on success and -1 on error, errno is set appropriately
 */
int _putfd(char c, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}

/**
 * _putsfd - function that prints an input string
 *
 * @str:the string to be printed
 * @fd:file descriptor to write
 *
 * Return: the number of characters to print
 */
int _putsfd(char *str, int fd)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str)
	{
		j += _putfd(*str++, fd);
	}
	return (j);
}
