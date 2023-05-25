#include "shell.h"
/**
 * __env - prints environment variables
 * @args: arguments
 *
 * Return: 1 on success, 0 otherwise
 */

int env_p(char **args)
{
    	int i = 0;
    	(void)(**args);

    	while (environ[i])
    	{
        	write(1, environ[i], strlen(environ[i]));
        	write(1, "\n", 1);
        	i++;
    	}
    	return (-1);
}