#include "shell.h"

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
