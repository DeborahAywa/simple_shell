#include "shell.h"
#include <stdlib.h>

/**
 * is_chain - function that tests if current characters
 * in buffer is a chain delimeter
 *
 * @buf: character buffer
 * @command:struct containing potential arguments
 * @p:address of current position in buffer
 *
 * Return: 1 if chain delimeter, otherwise 0
 */
int is_chain(command_t *command, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		command->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		command->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		command->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - function that checks, should continue chaining based
 * on the last status
 *
 * @command:structure of the arguments passed
 * @buf:the character buffer
 * @p:address of current position in buf
 * @i:starting position in buf
 * @len:length of buf
 *
 * Return:void
 */
void check_chain(command_t *command, char *buf, size_t *p,
		size_t i, size_t len)
{
	size_t j = *p;

	if (command->cmd_buf_type == CMD_AND)
	{
		if (command->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (command->cmd_buf_type == CMD_OR)
	{
		if (!command->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	*p = j;
}

/**
 * replace_alias - function that replaces an aliases in the tokenized string
 *
 * @command:structure of potential arguments
 *
 * Return:1 if replaced, 0 otherwise
 */
int replace_alias(command_t *command)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(command->alias, command->argv[0], '=');
		if (!node)
			return (0);
		free(command->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		command->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - function that replaces variables in the tokenized
 * string
 *
 * @command:structure of arguments passed
 * Return: 1 if replaces , 0 otherwise
 */
int replace_vars(command_t *command)
{
	int i = 0;
	list_t *node;

	for (i = 0; command->argv[i]; i++)
	{
		if (command->argv[i][0] != '$' || !command->argv[i][1])
			continue;
		if (!_strcmp(command->argv[i], "$ ?"))
		{
			replace_string(&(command->argv[i]),
					_strdup(convert_number(command->status, 10, 0)));
			continue;
		}
		if (!_strcmp(command->argv[i], "$$"))
		{
			replace_string(&(command->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(command->env, &command->argv[i][1], '=');
		if (node)
		{
			replace_string(&(command->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&command->argv[i], _strdup(" "));
	}
	return (0);
}

/**
 * replace_string - function that replaces a string
 *
 * @s1:address of old string
 * @s2:address of new string
 *
 * Return: 1 on success 0 otherwise
 */
int replace_string(char **s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	free(*s1);
	*s1 = s2;
	return (1);
}
