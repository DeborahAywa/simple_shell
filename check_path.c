#include "shell.h"
/**
 * check_path - function to check the path
 * of the string passed
 * @str:string to be checked
 * Return: command
 */
char *check_path(char *str)
{
	char *path = getenv("PATH");
	char *path_cpy, *path_tkn, *full_path;

	if (path)
	{
		path_cpy = strdup(path);
		path_tkn = strtok(path_cpy, ":");
		while (path_tkn != NULL)
		{
			full_path = malloc(LEN);

			dn_strcpy(full_path, path_tkn);
			_strcat(full_path, "/");
			_strcat(full_path, str);
			_strcat(full_path, "\0");
			if (access(full_path, X_OK) == 0)
			{
				free(path_cpy);
				return (full_path);
			}
			else
			{
				free(full_path);
				path_tkn = strtok(NULL, ":");
			}
		}
		free(path_cpy);
		if (access(str, X_OK) == 0)
			return (str);

		return (NULL);
	}

	return (NULL);
}

