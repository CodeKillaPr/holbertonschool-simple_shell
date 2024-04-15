#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>

extern char **environ;

/* our own function prototypes */
void prompt(void);
char *read_line(void);
char **tokenize_input(char *line);
int execute_child(char **tokens);

/* function prototypes for built-ins */
void display_env(void);

/* function prototypes for implementations */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_getenv(const char *name);
void free_grid(char **grid);

#endif /*_MAIN_H_*/
