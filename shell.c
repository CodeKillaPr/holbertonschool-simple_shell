#include "shell.h"

char *last_command = NULL; // To store the last command for history feature

/**
<<<<<<< HEAD
 * read_line - Function to read a line of input
 * Return: Line of input or NULL if EOF is reached
=======
 * read_line - Función para leer una línea de entrada
 * Return: Línea de entrada o NULL si se llega al final del archivo
>>>>>>> ff3c8e517fe36bb8d4e916f4296c53b90388b9da
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		free(line);
		return NULL;
	}

	if (last_command) free(last_command);
	last_command = strdup(line); // Update the last command

	return line;
}

/**
 * parse_line - Function to split a line into tokens
 * @line: Line of input
 * Return: Array of tokens
 */
char **parse_line(char *line)
{
	int bufsize = TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIMITER);
	while (token != NULL)
	{
		tokens[position++] = token;
		if (position >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Memory allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIMITER);
	}
	tokens[position] = NULL;
	return tokens;
}

/**
 * execute_command - Function to execute a command
 * @args: Array of tokens
 * Return: 1 to continue the shell, 0 to exit
 */
int execute_command(char **args)
{
	if (args[0] == NULL) return 1; // Empty command

<<<<<<< HEAD
	if (strcmp(args[0], "exit") == 0) return 0;
=======
	if (strcmp(args[0], "/bin/ls") == 0)
	{
		args[0] = "ls";
	}

>>>>>>> ff3c8e517fe36bb8d4e916f4296c53b90388b9da
	if (strcmp(args[0], "env") == 0)
	{
		for (char **env = environ; *env; env++)
			printf("%s\n", *env);
		return 1;
	}
	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1]) chdir(args[1]);
		else fprintf(stderr, "Expected argument to \"cd\"\n");
		return 1;
	}
	if (strcmp(args[0], "history") == 0)
	{
		if (last_command) printf("Last command: %s", last_command);
		else printf("No history available.\n");
		return 1;
	}

	return launch_process(args);
}

/**
 * launch_process - Function to launch a process
 * @args: Array of tokens
 * Return: 1 to continue the shell
 */
int launch_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) // Child process
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0) // Error forking
	{
		perror("Error");
	}
	else // Parent process
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 1;
}

/**
 * handle_sigint - Signal handler for SIGINT
 * @sig: Signal number
 */
void handle_sigint(int sig)
{
	printf("\nType 'exit' to close the shell\nsimple_shell$ ");
	fflush(stdout);
}

/**
 * shell_loop - Function to start the shell loop
 */
void shell_loop(void)
{
	signal(SIGINT, handle_sig
}
