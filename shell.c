#include "shell.h"

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char **parse_line(char *line)
{
	int bufsize = BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Error de asignación de memoria\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIMITER);
	while (token != NULL)
	{
		tokens[position++] = token;
		if (position >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Error de asignación de memoria\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIMITER);
	}
	tokens[position] = NULL;
	return tokens;
}

int launch_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) // Child process
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0) // Error forking
	{
		perror("Forking error");
	}
	else // Parent process
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 1;
}

int execute_command(char **args)
{
	if (args[0] == NULL)
	{
		// Empty command
		return 1;
	}

	if (strcmp(args[0], "exit") == 0)
	{
		// Exit command
		return 0;
	}

	if (strcmp(args[0], "/bin/ls") == 0)
	{
		// Translate to simple ls
		args[0] = "ls";
	}

	if (strcmp(args[0], "env") == 0)
	{
		// Environment variables command
		char **env = environ;
		while (*env)
		{
			printf("%s\n", *env++);
		}
		return 1;
	}

	// Any other command
	return launch_process(args);
}
