#include "shell.h"

/**
 * read_line - function to read the user input
 *
 * Return: string of user input
*/

char *read_line(void)
{
	char *entry_buffer;
	size_t entry_size;
	ssize_t val;
	int i = 0;

	val = getline(&entry_buffer, &entry_size, stdin);
	if (val == -1)
	{
		free(entry_buffer);
		exit(1);
	}
	/* Handle the new line character */
	while (entry_buffer[i])
	{
		if (entry_buffer[i] == '\n')
			entry_buffer[i] = '\0';
		i++;
	}

	return (entry_buffer);
}
