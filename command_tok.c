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
	char **string_array, *string_ptr;
	int i = 0, j = 0;

	string_array = malloc(sizeof(char *) * 10);
	if (string_array == NULL)
	{
		perror("Can't allocate space");
		exit(1);
	}
	string_ptr = strtok(str, " ");
	while (string_ptr != NULL)
	{
		while (string_ptr[i])
		{
			if (string_ptr[i] == '\n')
				string_ptr[i] = '\0';
			i++;
		}
		string_array[j] = string_ptr;
		j++;
		i = 0;
		string_ptr = strtok(NULL, " ");
	}
	string_array[j] = NULL;
	return (string_array);
}
