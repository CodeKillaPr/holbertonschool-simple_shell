#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;

#define BUFSIZE 64
#define MAX_COMMAND_LENGTH 1024
#define TOK_BUFSIZE 64
#define DELIMITER " \t\r\n\a"

#ifdef IGNORE_FPRINTF
#define fprintf(fp, ...) ((void)0)
#endif

/* Function declarations */
void shell_loop(void);
char *read_line(void);
char **parse_line(char *line);
int launch_process(char **args);
int execute_command(char **args);
void handle_sigint(int sig);

#endif /* SHELL_H */
