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
#include <stddef.h>

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

/**
 * struct command - pseudo-arguments to pass into function
 * allowing for uniform prototype for function pointer struct
 * @arg:string containing arguments
 * @argv:array of strings generated from arg
 * @path:path for the current command
 * @argc:argument count
 * @line_count:error count
 * @err_num:the error code for exit()s
 * @linecount_flag:counts line of input
 * @fname:file name
 * @env:copy of environ of linked list
 * @environ:copy of environment
 * @history:the history node
 * @alias:alias node
 * @env_changed:if the environment was changed
 * @status:return status of the last executed command
 * @cmd_buf:address of pointer to cmd_buf, chain buffer for memory management
 * @cmd_buf_type:CMD_type
 * @readfd:the file descriptor from which to read line input
 * @histcount:the number of lines from the history
 *
 */

typedef struct command
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;/*pointer to cmd;chain buffer for memory management*/
	int cmd_buf_type;
	int readfd;
	int histcount;
} command_t;

#define COMMAND_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}
/**
 * struct builtin - a builtin string having related functions
 * @func:the function
 * @type:builtin command flag
 */
typedef struct builtin
{
	char *type;
	int (*func)(command_t *);
} builtin_table;

/*string functions str_functions.c*/
int _strcmp(char *s1, char *s2);
char *_strcat(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

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
int free_pointer(void **str);
char **_strtok(char *str, char *d);

/*memory functions memory.c*/
char *_memset(char *s, char b, unsigned int n);
void *_realloc(void *ptr, unsigned int prev, unsigned int next);

/*list_t functions list_functions.c*/
size_t print_list_str(const list_t *h);
void free_list(list_t **head_ptr);
int delete_node_at_index(list_t **head, unsigned int index);
char **list_to_string(list_t *head);
ssize_t get_node_index(list_t *head, list_t *node);

/*more list_t functions list2_functions.c*/
size_t list_len(const list_t *h);
size_t print_list(const list_t *h);
list_t *node_starts_with(list_t *node, char *prefix, char s);

/*additional list_t functions list3_functions.c*/
list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);

/*command.c functions*/
void clear_command(command_t *command);
void set_command(command_t *command, char **av);
void free_command(command_t *command, int p);

/*functions to find if commands are in the path*/
int is_cmd(command_t *command, char *path);
char *dup_chars(char *pathstr, int start, int stop);
char *find_path(command_t *command, char *pathstr, char *cmd);

/*history functions file_history.c*/
char *get_history_file(command_t *command);
int write_history(command_t *command);
int read_history(command_t *command);
int build_history_list(command_t *command, char *buf, int linecount);
int renumber_history(command_t *command);

/* functions that use getline getline.c*/
ssize_t input_buf(command_t *command, char **buf, size_t *len);
ssize_t get_input(command_t *command);
ssize_t read_buf(command_t *command, char *buf, size_t *i);
int _getline(command_t *command, char **ptr, size_t *length);
void sigintHandler(__attribute__((unused))int sig_num);

/*Environment functions env_functions.c*/
int _myenv(command_t *command);
char *_getenv(command_t *command, const char *name);
int _mysetenv(command_t *command);
int _myunsetenv(command_t *command);
int populate_env_list(command_t *command);

/*More environment functions env2_functions.c*/
int my_unsetenv(command_t *command, char *var);

/*functions to handle errors error_functions.c*/
int _erratoi(char *s);
void print_error(command_t *command, char *estr);
int print_d(int input, int fd);
char *convert_number(long int num, int base, int flags);
void remove_comments(char *buf);

/*puts functions puts.c*/
int _eputchar(char c);
void _eputs(char *str);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/*the merged or chain functions used chain.c */
int is_chain(command_t *command, char *buf, size_t *p);
void check_chain(command_t *command, char *buf, size_t *p,
		size_t i, size_t len);
int replace_alias(command_t *command);
int replace_vars(command_t *command);
int replace_string(char **s1, char *s2);

/*builtin function emulators builtin_functions.c*/
int _myexit(command_t *command);
int _mycd(command_t *command);
int _myhelp(command_t *command);

/*more builtin function emulators builtin2_functions.c*/
int _myhistory(command_t *command);
int unset_alias(command_t *command, char *str);
int set_alias(command_t *command, char *str);
int print_alias(list_t *node);
int _myalias(command_t *command);

/*Functions that check if a shell is interactive, checks for delimeter*/
int interactive(command_t *command);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);

/*loop functions for the shell program*/
int prog_loop(command_t *command, char **av);
int find_builtin(command_t *command);
void find_cmd(command_t *command);
void fork_cmd(command_t *command);

/*the entry point of the shell program*/
int main(int ac, char **av);

/*functions to remove and set the environment variables*/
char **get_environ(command_t *command);
int _unsetenv(command_t *command, char *var);
int _setenv(command_t *command, char *var, char *value);

#endif
