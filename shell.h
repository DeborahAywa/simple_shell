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

/*READ AND WRITE BUFFERS*/
#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024
#define BUF_FLUSH -1

/*TO CONVERT NUMBERS*/
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/*MERGING COMMANDS*/
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/*when using getline()*/
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE "simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num:the number field
 * @str:a string
 * @next:point to the next node
 */

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

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

/*list_t functions list_functions.c*/
size_t print_list(const list_t *h);
void free_list(list_t *head);
int delete_node_at_index(list_t **head, unsigned int index);
char **list_to_string(list_t *head);
ssize_t get_node_index(list_t *head, list_t *node);

/*more list_t functions list2_functions.c*/
size_t list_len(const list_t *h);
size_t print_list2(const list_t *h);
list_t *node_starts_with(list_t *node, char *prefix, char s);

/*additional list_t functions list3_functions.c*/
list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str);
size_t print_list_str(const list_t *h);

#endif
