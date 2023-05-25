#include "shell.h"
/**
 * cmd - function that executes commands
 * @av:array of commands passed
 * @env:environment path array
 * Return:Nothing
 */

void cmd(char **av, char **env)
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
		if (*buff != '\n')
		{
			string = com_tok(buff);
			if (_strcmp("exit", string[0]) == 0)
			{
				free(buff);
				free(string);
				return;
<<<<<<< HEAD
			}
			else if (_strcmp(string[0], "env") == 0)
=======
			}else if(_strcmp(string[0],"env") == 0)
>>>>>>> 5903f8da5dd83683e753fee260a28324faf210d5
				env_p();

			exec(string, env);
		}
		free(buff);
		free(string);
	}
}
