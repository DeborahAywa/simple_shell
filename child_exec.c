#include "shell.h"

/**
 * exec-function that executes string passed
 * to the command line in the child process
 *
 * @string:Array of string from the command
 * line
 * @envp:environment variables from the parent
 *
 * Return:returns void
 */

void exec(char **string, char *envp[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		free(string);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(string[0], string, envp) == -1)
			perror("Error (execve)");
	}
	else
	{
		wait(&status);
	}
}
