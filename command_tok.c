#include "shell.h"
/**
 * com_tok- function that tokenizes a string
 * passed by the user
 *
 * @str:string to be tokenized
 * Return:Array of strings
 */
char **com_tok(char *str)
{
	int buffsize = LEN;
	char *token;
	char *token_delim = " ";
	char **token_array = malloc(sizeof(char) * buffsize);
	int i = 0;

	if (!token_array)
	{
		perror("Allocation Error");
		exit(1);
	}

	token = strtok(str, token_delim);

	while (token != NULL)
	{
		token_array[i] = token;
		i++;

		if (i >= buffsize)
		{
			buffsize += LEN;
			token_array = malloc(sizeof(char) * buffsize);
			if (!token_array)
			{
				perror("Allocation Error");
				exit(1);
			}
		}

		token = strtok(NULL, token_delim);
	}

	token_array[i] = NULL;
	return (token_array);
}

