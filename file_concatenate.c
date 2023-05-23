#include "shell.h"

/**
 * file_link - function that links a file to it's
 * path
 *
 * @str:string to be checked
 * Return:the file that has been linked with path
 */

char *file_link(char *str)
{
	DIR *dir = opendir("/bin/");
	char *temp, *cats;
	struct dirent *subst;

	if (dir == NULL)
		return (NULL);
	subst = readdir(dir);
	while (subst != NULL)
	{
		temp = subst->d_name;
		if (_strcmp(temp, str) == 0)
		{
			cats = _strcat("/bin/", str);
			closedir(dir);
			return (cats);
		}
		subst = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}
