#include "shell.h"
/**
 * env_p - prints environment variables
 *
 * Return: 1 on success, 0 otherwise
 */

int env_p(void)
{
    	int i = 0;
    	
        /*global external environ declared in shell.h*/
    	while (environ[i])
    	{
        	write(1, environ[i], strlen(environ[i]));
        	write(1, "\n", 1);
        	i++;
    	}
    	return (-1);
}