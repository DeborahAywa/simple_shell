#include "shell.h"

/**
 * interactive - function that returns true if shell is interactive
 *
 * @command:structure containing arguments to be passed
 *
 * Return:1 if shell is interactive, 0 otherwise
 */
int interactive(command_t *command)
{
	return (isatty(STDIN_FILENO) && command->readfd <= 2);
}

/**
 * is_delim - function that checks if a character is a delimeter
 *
 * @c:the character to check
 * @delim:the delimeter
 *
 * Return:1 if true and 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - function that checks for alphabetical character
 *
 * @c:the character to input
 *
 * Return:1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - function that converts a string to an integer
 * @s: string to be converted
 *
 * Return:0 if no numbers in the string, otherwise converted number
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int res = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			res *= 10;
			res += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -res;
	else
		output = res;
	return (output);
}
