#include "shell.h"

/**
 * shell_loop - Function to start the shell loop
 */
void shell_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("simple_shell ");
		line = read_line();
		args = parse_line(line);
		status = execute_command(args);

		free(line);
		free(args);
	} while (status);
}

/**
 * read_line - Function to read a line of input from stdin
 *
 * Return: The input line
 */
char *read_line(void)
{
	char *line = NULL;
	ssize_t bufsize = 0;

	getline(&line, (size_t *)&bufsize, stdin);

	return (line);
}

/**
 * parse_line - Function to parse a line into tokens
 *
 * @line: The input line
 * Return: Array of tokens
 */
char **parse_line(char *line)
{
	int bufsize = BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIMITER);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, DELIMITER);
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * launch_process - Function to launch a process
 *
 * @args: Array of arguments for the process
 * Return: 1 if successful
 */
int launch_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("shell");
	}
	else
	{

		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

/**
 * execute_command - Function to execute a command
 *
 * @args: Array of arguments for the command
 * Return: 0 if the command is "exit", 1 otherwise
 */
int execute_command(char **args)
{
	if (args[0] == NULL)
	{
		return (1);
	}

	if (strcmp(args[0], "exit") == 0)
	{
		return (0);
	}

	if (strcmp(args[0], "env") == 0)
	{
		char **env = environ;

		while (*env)
		{
			printf("%s\n", *env++);
		}
		return (1);
	}

	return (launch_process(args));
}
