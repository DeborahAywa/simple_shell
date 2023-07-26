#include "shell.h"

/**
 * get_environ - function that returns the string array
 * copy of the environment
 *
 * @command:structure containing the arguments
 *
 * Return: Always return 0
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
 * my_unsetenv - function that removes an environment variable
 * @command:structure containing commands
 * @var:the environment string
 *
 * Return:1 when environment variable is removed and 0 otherwise
 */
int my_unsetenv(command_t *command, char *var)
{
	list_t *node = command->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			command->env_changed = delete_node_at_index(&(command->env), i);
			i = 0;
			node = command->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (command->env_changed);
}

/**
 * _setenv - initializes new or modifiies a variable
 * @command: structure containing arguments
 * @var:environment string properties
 * @value: environment string var value
 *
 * Return:Always return 0
 */
int _setenv(command_t *command, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (1);
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
