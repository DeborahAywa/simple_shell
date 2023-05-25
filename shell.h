#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <stdbool.h>

#define LEN 1000
extern char **environ;

int exec(char **string, char *envp[]);
char *read_line(void);
int _strcmp(char *s1, char *s2);
char **com_tok(char *str);
char *file_link(char *str);
char *check_path(char *str);
char *_strcat(char *dest, char *src);
void cmd(char **env);
int main(int ac, char **env);

#endif
