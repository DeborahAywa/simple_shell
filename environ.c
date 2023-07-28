#include "shell.h"

/**
 * get_environ - function that return the string array copy
 * of the environment
 *
 * @command:structure containing potential arguments to be
 * passed
 *
 * Return:Always return 0
 */
char **get_environ(command_t *command)
{
	if (!command->environ || command->env_changed)
	{
		command->environ = list_to_string(command->env);
		command->env_changed = 0;
	}
	return (command->environ);
}

/**
 * _unsetenv - function that removes the environment variable
 *
 * @command:structure containing potential arguments
 * @var:string env variable property
 *
 * Return: 1 when deleted and 0 otherwise
 */
int _unsetenv(command_t *command, char *var)
{
	list_t *node = command->env;
	size_t j;
	char *p;

	if (!node || !var)
		return (0);
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			command->env_changed = delete_node_at_index(&(command->env), j);
			j = 0;
			node = command->env;
			continue;
		}
		node = node->next;
		j++;
	}
	return (command->env_changed);
}

/**
 * _setenv - function that initializes a new environment variable
 *
 * @command:structure containing potential arguments
 * @var:property of string environment variable
 * @value:string environment value property
 *
 * Return:Always return 0
 */
int _setenv(command_t *command, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);
	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = command->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			command->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(command->env), buf, 0);
	free(buf);
	command->env_changed = 1;
	return (0);
}
