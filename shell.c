#include "shell.h"

/**
 * read_line - Función para leer una línea de entrada
 * Return: Línea de entrada o NULL si se llega al final del archivo
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

	return (line);
}

/**
 * parse_line - Función para dividir una línea en tokens
 * @line: Línea de entrada
 * Return: Array de tokens
 */
char **parse_line(char *line)
{
	int bufsize = BUFSIZE;
	int position = 0;
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
		tokens[position] = token;
		position++;

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
	return (tokens);
}

/**
 * execute_command - Función para ejecutar un comando
 * @args: Array de tokens
 * Return: 1 si el comando se ejecuta correctamente, 0 si se sale
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

/**
 * launch_process - Función para lanzar un proceso
 * @args: Array de tokens
 * Return: 1 si el proceso se lanza correctamente
 */
int launch_process(char **args)
{
	pid_t pid;
	int status;

	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("simple_shell$");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("simple_shell$");
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
