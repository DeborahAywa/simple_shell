#include "main.h"

/**
 * read_line - read the user input
 * 
 * Return - string of user input
*/

char *read_line(void)
{
    char *entry_buffer;
    size_t entry_size = 0;
    ssize_t val = getline(&entry_buffer,&entry_size,stdin);
    if (val == -1) 
    {
        free(entry_buffer);
        exit(1);
    }
    return entry_buffer;
}

