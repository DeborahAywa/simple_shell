#include shell.h
#include <unistd.h>

/**
 * _strcmp-function to compare two strings
 * @s1:string to compare to s2
 * @s2:string to compare to s1
 * Return:end program with 0
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] > s2[i])
				return (s1[i] - s2[i]);
			else if (s1[i] < s2[i])
				return (s1[i] - s2[i]);
		}
		else
			return (0);
	}
	return (0);
}

/**
 * *_strcat-function that concatenates string/
 * src to dest /
 *
 * @dest:the destination where src is to be /
 * appended
 *
 * @src:the string to be appended
 *
 * Return:a pointer to string dest
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	int p;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		j++;
	}
	for (p = 0; p <= j; p++)
	{
		dest[i + p] = src[p];
	}
	return (dest);
}

/**
 * _strlen-function to return the length
 * @s:string to be counted
 *
 * Return:returns length
 */

int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
 ** _strcpy-function that copies the string pointed\
 * by src including (\0) to buffer pointed by dest
 * @dest:destination of the string
 * @src:string to be copied
 *
 * Return:return copied string
 */

char *_strcpy(char *dest, char *src)
{
	int length;
	int i;

	while (*src)
	{
		src++;
		length++;
	}
	for (i = 0; i < length; i++)
		src--;
	for (i = 0; i < length; i++)
	{
		dest[i] = *src;
		src++;
	}
	dest[i] = *src;

	return (dest);
}

/**
 * _puts-function that prints a string
 *
 * @str:string to be printed
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}
