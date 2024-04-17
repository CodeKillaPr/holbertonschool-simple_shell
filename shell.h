#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

#define BUFSIZE 1024
#define MAX_COMMAND_LENGTH 1024
#define TOK_BUFSIZE 64
#define DELIMITER " \t\r\n\a"

/* Function declarations */
void shell_loop(void);
char *read_line(void);
char **parse_line(char *line);
int launch_process(char **args);
int execute_command(char **args);

#endif /* SHELL_H */
