#ifndef SHELL_H
#define SHELL_H

void exec(char **string, char *envp[]);
char *read_line(void);
int _strcmp(char *s1, char *s2);
char **com_tok(char *str);
char *file_link(char *str);
int check_path(char *str);
char *_strcat(char *dest, char *src);

#endif
