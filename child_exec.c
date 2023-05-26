#include "shell.h"
/**
 * exec-function that executes string passed
 *
 * @string:Array of string from the command
 * line
 * @envp:environment variables from the parent
 *
 * Return:returns -1 on failure
 */
int exec(char **string, char *envp[])
{
	char *command = NULL;
	char *full_path = NULL;
	pid_t pid;
	int status;

	if (string)
	{
		command = string[0];

		full_path = check_path(command);
		pid = fork();

		if (pid == 0)
		{
			if (execve(full_path, string, envp) == -1)
				perror("execve failed");
			exit(1);
		}
		else if (pid < 0)
			perror("fork() failed");
		else
		{
			do waitpid(pid, &status, WUNTRACED);
			while (!WIFEXITED(status) && !WIFSIGNALED(status));
		free(full_path);
		}
	}

	return (-1);

}
