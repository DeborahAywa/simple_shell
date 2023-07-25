#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/*string functions str_functions.c*/
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void _puts(char *str);

/*additional string functions str2_functions.c*/
char *_strdup(const char *str);
char *_strncat(char *dest, char *src, int n);
char *_strchr(char *s, char c);
char *starts_with(const char *haystack, const char *needle);
int _putchar(char c);

/*more string functions str3_functions.c*/
void _puts(char *str);
char *_strncpy(char *dest, char *src, int n);
void free_string(char **str);
int free_pointer(void *str);
char **_strtok(char *str, char *d);

/*memory functions memory.c*/
char *_memset(char *s, char b, unsigned int n);
void *_realloc(void *ptr, unsigned int prev, unsigned int next);

#endif
