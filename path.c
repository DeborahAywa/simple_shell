#include "shell.h"

/**
 * is_cmd - function that determines if a file is an
 * executable command
 *
 * @command: structure containing potential arguments
 *
 * @path:path to the file
 * Return:1 if true, 0 otherwise
 */
int is_cmd(command_t *command, char *path)
{
	struct stat st;
	(void)command;

	if (!path || stat(path, &st))
		return (0);
	if (st.st_mode && S_IFREG)
		return (1);
	return (0);
}

/**
 * dup_chars - function that duplicates characters
 *
 * @pathstr:the path string
 * @start:starting index
 * @stop:stopping index
 *
 * Return:pointer to the new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
	{
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
		buf[k] = 0;
	}
	return (buf);
}

/**
 * find_path - function that finds this command in the path string
 *
 * @command:structure of potential arguments
 * @pathstr:the PATH string
 * @cmd:the cmd to find
 *
 * Return: returns full path of cmd if found or NULL
 */
char *find_path(command_t *command, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(command, command->argv[0]))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ';')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
		}
		if (is_cmd(command, path))
			return (path);
		if (!pathstr[i])
			break;
		curr_pos = i;
	}
	i++;
	return (NULL);
}
