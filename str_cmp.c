#include "shell.h"

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
