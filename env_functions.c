#include "shell.h"

/**
 * _myenv - funtion that prints the current environment
 * @command:structure containing arguments
 *
 * Return:returns 0
 */
int _myenv(command_t *command)
{
	print_list_str(command->env);
	return (0);
}

/**
 * _getenv -function that  gets the value of an environ variable
 * @command:structure containing arguments
 * @name:the env variable name
 *
 * Return:return the value
 */
char *_getenv(command_t *command, const char *name)
{
	list_t *node = command->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - function that initializes a new environment variable
 * @command:structure containing arguments
 * Return: Always return 0
 */
int _mysetenv(command_t *command)
{
	if (command->argc != 3)
	{
		_eputs("wrong number of arguments \n");
		return (1);
	}
	if (_setenv(command, command->argv[1], command->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - removes an environment variable
 * @command:structure containing arguments
 *
 * Return:Always return 0
 */
int _myunsetenv(command_t *command)
{
	int j;

	if (command->argc == 1)
	{
		eputs("Few arguments .\n");
		return (1);
	}
	for (j = 1; j <= command->argc; j++)
		_unsetenv(command, command->argv[i]);
	return (0);
}

/**
 * populate_env_list - function that populates environment linked list
 * @command: structure containing arguments
 *
 * Return:Always return 0
 */
int populate_env_list(command_t *command)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	command->env = node;
	return (0);
}
