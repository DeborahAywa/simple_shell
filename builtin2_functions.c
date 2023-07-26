#include "shell.h"

/**
 * _myhistory - display the history list, one
 * command by line, preceeded with line numbers,
 * starting at 0
 *
 * @command:struct containing potential arguments
 *
 * Return:Always 0
 */
int _myhistory(command_t *command)
{
	print_list(command->history);
	return (0);
}

/**
 * unset_alias - function that puts alias to string
 *
 * @command:struct containing potential arguments
 * @str: the string alias
 *
 * Return:Always 0 and 1 on error
 */
int unset_alias(command_t *command, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(command->alias), get_node_index(command->alias, node_starts_with(command->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - function that sets alias to string
 * @str:string alias
 *
 * @command:struct containing potential arguments
 *
 * Return:Always 0 on success, 1 on error
 */
int set_alias(command_t *command, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(command, str));
	unset_alias(command, str);
	return (add_node_end(&(command->alias), str, 0) == NULL);
}

/**
 * print_alias - function that prints an alias story
 * @node:the alias node
 *
 * Return:Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\");
		_puts(p + 1);
		_puts("'\n');
		return (0);
	}
	return (1);
}

/**
 * _myalias - function that mimics the alias builtins
 * @command:structure of potential arguments
 *
 * Return:Always 0
 */
int _myalias(command_t *command)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (command->argc == 1)
	{
		node = command->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; command->argv[i]; i++)
	{
		p = _strch(command->argv[i], '=');
		if (p)
			set_alias(command, command->argv[i]);
		else
			print_alias(node_starts_with(command->alias, command->argv[i], '='));
	}
	return (0);
}
