#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
#define MAX_INPUT_SIZE 1024
#define MAX_CMD_SIZE 1024
#define DELIM " \t\r\n\a"
#define PROMPT "simple_shell "

int _printenv(void);
int cmd_read(char *s, size_t __attribute__((unused)) file_stream, char *name);
char *pathfinder(char *cmd);
void print_not_found(char *cmd, char *name);
int call_command(char *cmd_arr[], char *name);
int _str_n_cmp(char *s1, char *s2, int n);
char *_getenv(char *var);
char *path_not_find(char *cmd);

#endif /* SIMPLE_SHELL_H */
