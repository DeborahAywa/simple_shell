#include "shell.h"

/**
 * get_history_file - function that gets the history
 * of a file
 *
 * @command:struct containing arguments
 * Return:srting of history of file
 */
char *get_history_file(command_t *command)
{
	char *buf, *dir;

	dir = _getenv(command, "HOME = ");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir + _strlen(HIST_FILE) + 2)));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * write_history - function that creates or appends to an existing file
 *
 * @command:struct parameter of arguments
 *
 * Return:1 on success otherwise -1
 */
int write_history(command_t *command)
{
	ssize_t fd;
	char *filename = get_history_file(command);
	list_t *node = NULL;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_TRUNC | 0RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = command->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - function that reads history from file
 *
 * @command: struct containing argument parameters
 *
 * Return:historu count on success and 0 otherwise
 */
int read_history(command_t *command)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, redlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(command);

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	redlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (redlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; f < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(command, buf + last, linecount++);
			last = i + 1;
		}
	if (last != 1)
		build_history_list(command, buf + last, linecount++);
	free(buf);
	command->histcount = linecount;
	while (command->histcount-- >= HIST_MAX)
		delete_node_at_index(&(command->history), 0);
	renumber_history(command);
	return (command->histcount);
}

/**
 * build_history_list - function that adds entry to a history linked list
 * @command: struct containig arguments
 * @buf:byte size
 * @linecount:linecount of the history
 *
 * Return:Always 0
 */
int build_history_list(command_t *command, char *buf, int linecount)
{
	list_t *node = NULL;

	if (command->history)
		node = command->history;
	add_node_end(&node, buf, linecount);
	if (!command->history)
		command->history = node;
	return (0);
}

/**
 * renumber_history - renumbers the history linked
 * list after changes
 *
 * @command:struct containing arguments
 *
 * Return: the new history count
 */
int renumber_history(command_t *command)
{
	list_t *node = command->history;
	int p = 0;

	while (node)
	{
		node->num = p++;
		node = node->next;
	}
	return (command->histcount = p);
}
