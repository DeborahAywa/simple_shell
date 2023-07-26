#include "shell.h"

/**
 * clear_command - function that initializes command_t struct
 * @command: struct containing potential arguments
 */
void clear_command(command_t *command)
{
	command->arg = NULL;
	command->argv = NULL;
	command->path = NULL;
	command->argc = 0;
}

/**
 * set_command - function that initializes command_t struct
 * @command:struct containing potential arguments
 * @av:argument vector
 */
void set_command(command_t *command, char **av)
{
	int i = 0;

	command->fname = av[0];
	if (command->arg)
	{
		command->argv = strtok(command->arg, "\t");
		if (!command->argv)
		{
			command->argv = malloc(sizeof(char *) * 2);
			if (command->argv)
			{
				command->argv[0] = strdup(command->argv);
				command->argv[1] = NULL;
			}
		}
		for (i = 0; command->argv && command->argv[i]; i++)
			command->argc = i;
		replace_alias(command);
		replace_vars(command);
	}
}

/**
 * free_command - function that frees command_t struct fieids
 * @command:struct containing potential arguments
 * @p:true for all fields
 */
void free_command(command_t *command, int p)
{
	free_string(command->argv);
	command->argv = NULL;
	command->path = NULL;

	if (p)
	{
		if (!command->cmd_buf)
			free(command->argv);
		if (command->env)
			free_list(&(command->env));
		if (command->history)
			free_list(&(command->history));
		if (command->alias)
			free_list(&(command->alias));
		free_string(command->environ);
		command->environ = NULL;
		free_pointer((void **) command->cmd_buf);
		if (command->readfd > 2)
			close(command->readfd);
		_putchar(BUF_FLUSH);
	}
}
