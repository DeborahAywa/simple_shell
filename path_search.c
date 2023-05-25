#include "shell.h"
/**
 * search_path - searches for the path of a command in environment
 * @cmd: command whose path is searched for
 *
 * Return: full path of command, NULL otherwise
 */
char *search_path(char *cmd)
{
	char *path = getenv("PATH");
	char *duplicate, *path_token, *full_path;

	if(path)
	{
		duplicate = strdup(path);
		path_token = strtok(duplicate, ":");

		while(path_token != NULL)
		{
			full_path = malloc(BUFFER_SIZE);
			strcpy(full_path, path_token);
			strcat(full_path, "/");
			strcat(full_path, cmd);
			strcat(full_path, "\0");
			if(access(full_path, X_OK) == 0)
			{
				free(duplicate);
				return(full_path);
			}
			else 
			{
				free(full_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(duplicate);
		if(access(cmd, X_OK) == 0)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}