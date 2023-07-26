#include "shell.h"

/**
 * _myexit function that exits shell
 * @command: structure containing potential arguments
 *
 * Return:exits with a given exit state 0. If
 * command.argv[0] != "exit"
 */
int _myexit(command_t *command)
{
	int exit_check;

	if (command->argv[1])
	{
		exit_check = _erratoi(command->argv[1]);
		if (exit_check == -1)
		{
			command->status = 2;
			print_error(command, "Illegal no: ");
			_eputs(command->argv[1]);
			_eputchar('\n');
			return (1);
		}
		command->err_num = _erratoi(command->argv[1]);
		return (-2);
	}
	command->err_num = -1;
	return (-2);
}

/**
 * _mycd - function that changes thecurrent directory of the
 * process
 * @command:structure containing potential arguments
 *
 * Return:Always 0
 */
int _mycd(command_t *command)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here << \n");
	if (!command->argv[1])
	{
		dir = _getenv(command, "HOME = ");
		if (!dir)
			chdir_ret = chdir((dir = _getenv(command, "PWD = ")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(command->argv[1], "-") == 0)
	{
		if (!_getenv(command, "OLDPWD = "))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(command, "OLDPWD = "));
		_putchar('\n');
		chdir_ret = chdir((dir = _getenv(command, "OLDPWD =")) ? dir : "/");
	}
	else
		chdir_ret = chdir(command->argv[1]);
	if (chir_ret == -1)
	{
		print_error(command, "can't change directory to ");
		_eputs(command->argv[1], _eputchar('\n'));
	}
	else
	{
		_setenv(command, "OLDPWD");
		_getenv(command, "PWD = ");
		_setenv(command, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - function that changes the current directory of the process
 * @command:structure of the potential arguments
 *
 * Return: Always 0
 */
int _myhelp(command_t *command)
{
	char **arg_array;

	arg_array = command->argv;
	_puts("help call, function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
