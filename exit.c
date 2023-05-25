#include "shell.h"
/**
 * __exit - terminates a process
 * @args: empty args
 *
 * Return: 0 to terminate the process
 */
int dn_exit(char **par)
{
    	if (par[1])
    	{
            /*if argument passed, return it*/
        	return (atoi(par[1]));
    	}
    	else
    	{
        	return (0);
    	}
}
