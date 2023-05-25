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
	char **string_array, *string_ptr, **temp;
	int i = 0, j = 0, n = 10;

	string_array = malloc(sizeof(char *) * n);
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

		/*Double the size of memory*/
		if (j == n)
		{
			n *= 2;
			temp = realloc(string_array, sizeof(char *) * n);
			if (temp == NULL)
			{
				perror("Cannot reallocate space");
				exit(1);
			}
			string_array = temp;
		}
	}
	string_array[j] = NULL;
	return (string_array);
}
