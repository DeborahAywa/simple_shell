#include "shell.h"
/**
 * cmd - function that executes commands
 * @env:environment path array
 * Return:Nothing
 */

void cmd(char **env)
{
	char *buff;
	const char *prompt = "#cisfun$ ";
	size_t len = 9;
	ssize_t a;
	char **string;
	bool pipe = false;

	while (1 && !pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			pipe = true;
		a = write(1, prompt, len);
		if (a == -1)
			return;
		buff = read_line();
		if (!_strcmp("", buff))
		continue;
		if (*buff != '\n')
		{
			string = com_tok(buff);
			if (_strcmp("exit", string[0]) == 0)
			{
				free(buff);
				free(string);
				return;
			}
			exec(string, env);
		}
		free(buff);
		free(string);
	}
}
