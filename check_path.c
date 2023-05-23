#include "shell.h"

/**
 * check_path - function to check the path
 * of the string passed
 * @str:string to be checked
 * Return:1 on success and 0 on failure
 */
int check_path(char *str)
{
	char *path = "/bin/", *ptr, *j;
	int p = 0, q = 0;

	ptr = malloc(sizeof(char) * 100);
	if (ptr == NULL)
		return (0);
	while (path[p] != '\0')
	{
		if (path[p] != str[p])
		{
			free(ptr);
			return (0);
		}
		p++;
	}
	while (str[p] != '\0')
	{
		ptr[q] = str[p];
		q++;
		p++;
	}
	ptr[q] = '\0';
	j = file_link(ptr);
	if (j != NULL)
	{
		free(ptr);
		return (1);
	}
	return (0);
}
