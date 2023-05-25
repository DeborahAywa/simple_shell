#include "shell.h"

/**
 * main - function that executes
 * commands passed
 *
 * @ac:Number of arguments passed
 * @env:environment list
 *
 * Return:Always return 0
 */

int main(int ac, char **env)
{
	while (ac)
		cmd(env);
	return (0);
}
