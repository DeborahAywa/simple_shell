#include "shell.h"

/**
 * prog_loop - function that has the main shell loop
 *
 * @command: structure of potential arguments
 * @av:the argument vector
 *
 * Return:0 on success, 1 on error or error code
 */
int prog_loop(command_t *command, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_command(command);
		if (interactive(command))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(command);
		if (r != -1)
		{
			set_command(command, av);
			builtin_ret = find_builtin(command);
			if (builtin_ret == -1)
				find_cmd(command);
		}
		else if (interactive(command))
			_putchar('\n');
		free_command(command, 0);
	}
	write_history(command);
	free_command(command, 1);
	if (!interactive(command) && command->status)
		exit(command->status);
	if (builtin_ret == -2)
	{
		if (command->err_num == -1)
			exit(command->status);
		exit(command->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - function that finds a builtin command
 *
 * @command: structure of potential arguments
 *
 * Return: -1 if builtin is not found
 * 0 if builtin executes successfully
 * 1 found but not successfully
 * -2 if builtin signals exit()
 */
int find_builtin(command_t *command)
{
	int i, builtin_in_ret = -1;

	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"cd", _mycd}
		{"alias", _myalias},
			{NULL, NULL}
	};
	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(command->argv[0], builtintb1[1].type) == 0)
		{
			command->line_count++;
			builtin_in_ret = builtintbl[i].func(command);
			break;
		}
	return (builtin_in_ret);
}

/**
 * find_cmd - function that finds command in path
 *
 * @command: structure of potential arguments
 *
 * Return: nothing
 */
void find_cmd(command_t *command)
{
	char *path = NULL;
	int i, k;

	command->path = command->argv[0];
	if (command->linecount_flag == 1)
	{
		command->line_count++;
		command->linecount_flag = 0;
	}
	for (i = 0; k = 0; command->arg[i]; i++)
		if (!is_delim(command->arg[i], "\t\n"))
			k++;
	if (!k)
		return;
	path = find_path(command, _getenv(command, "PATH = "), command->argv[0]);
	if (path)
	{
		command->path = path;
		fork_cmd(command);
	}
	else
	{
		if ((interactive(command) || _getenv(command, "PATH = ")
					|| command->argv[0][0] == '/')
					&& is_cmd(command, command->argv[0]))
			fork_cmd(command);
		else if (*(command->arg) != '\n')
		{
			command->status = 127;
			print_error(command, "not found \n");
		}
	}
}

/**
 * fork_cmd - function that forks an exec thread to ren cmd
 *
 * @command: structure of potential arguments
 *
 * Return: void
 */
void fork_cmd(command_t *command)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/*TODO: PUT ERROR FUNCTION*/
		perror("Errror: ");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(command->path, command->argv, get_environ(command)) == -1)
		{
			free_command(command, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/*TODO:PUT ERROR FUNCTION*/
	}
	else
	{
		wait(&(command->status));
		if (WIFEXITED(command->status))
		{
			command->status = WEXITSTATUS(command->status);
			if (command->status == 126)
				print_error(command, "Permission denied \n");
		}
	}
}
