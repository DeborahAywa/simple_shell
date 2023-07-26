#include "shell.h"

/**
 * input_buf - function that buffers chained commands
 *
 * @command: structure of potential argument
 * @buf:address of buffer
 * @len:address of len variable
 *
 * Return:return bytes read
 */
ssize_t input_buf(command_t *command, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#IF USE _GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(command, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}
			command->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(command, *buf, command->histcount++);
			/*if (_strch(*buf, ';')) is the command chain*/
			{
				*len = r;
				command->cmd_buf = buf;
			}
		}
	}
	return (r);
}

/**
 * get_input - function that gets a line minus the new line
 * @command: structure of potential arguments
 *
 * Return:return the bytes read
 */
ssize_t get_input(command_t *command)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(command->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(command, &buf, &len);
	if (r == 1)
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;
		check_chain(command, buf, &j, i, len);
		while (j < len)
		{
			if (is_chain(command, buf, &j))
				break;
			j++;
		}
		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			command->cmd_buf_type = CMD_NORM;
		}
		*buf_p = p;
		return (_strlen(p));
	}
	*buf_p = buf;
	return (r);
}

/**
 * read_buf - function that reads a buffer
 * @command: structure of potential arguments
 * @buf:buffer
 * @i:size
 *
 * Return: r
 */
ssize_t read_buf(command_t *command, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(command->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * _getline - function that gets the next line of input from STDIN
 *
 * @command: structure of potential arguments
 * @ptr:address of pointer to buffer, preallocate or NULL
 * @length:size of preallocated ptr buffer if not NULL
 *
 * Return:s
 */
int _getline(command_t *command, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;
	r = read_buf(command, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);
	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);
	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);
	s += k - i;
	i = k;
	p = new_p;
	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler - function that blocks ctrl-c;
 * @sig_num:the signal number
 *
 * Return: nothing
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
