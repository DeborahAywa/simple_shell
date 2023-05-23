#include "shell.h"

/**
 * main - function that executes
 * commands passed
 *
 * @ac:Number of arguments passed
 * @av:argument to pass to new program
 * @env:environment list
 *
 * Return:Always return 0
 */

int main(int ac, char **av, char **env)
{
	while (ac)
		cmd(av, env);
	return (0);
}
