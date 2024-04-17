#include "shell.h"
/**
 * read_line - Función para leer una línea de entrada
 * Return: Línea de entrada o NULL si se llega al final del archivo
 */
char *read_line(void)
{
	int bufsize = BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (buffer == NULL)
	{
		fprintf(stderr, "Error de asignación de memoria\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		c = getchar();

		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		}
		else
		{
			buffer[position] = c;
		}
		position++;

		if (position >= bufsize)
		{
			bufsize += BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (buffer == NULL)
			{
				fprintf(stderr, "Error de asignación de memoria\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

/**
 * parse_line - Función para dividir una línea en tokens
 * @line: Línea de entrada
 * Return: Array de tokens
 */
char **parse_line(char *line)
{
	int bufsize = TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (tokens == NULL)
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
			bufsize += TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (tokens == NULL)
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

/**
 * execute_command - Función para ejecutar un comando
 * @args: Array de tokens
 * Return: 1 si el comando se ejecuta correctamente, 0 si se sale
 */
int execute_command(char **args)
{
<<<<<<< HEAD
=======

	int result = launch_process(args);

>>>>>>> Nelson
	if (args[0] == NULL)
	{
		return (1);
	}

	if (strcmp(args[0], "exit") == 0)
	{
		return (0);
	}

<<<<<<< HEAD
	return (launch_process(args));
=======
	if (strcmp(args[0], "env") == 0)
	{
		char **env = environ;

		while (*env)
		{
			printf("%s\n", *env++);
		}
		return (1);
	}

	return result;
>>>>>>> Nelson
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

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return -1;
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
<<<<<<< HEAD
			perror("simple_shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("simple_shell");
=======
			perror("execvp");
			exit(EXIT_FAILURE);
		}
>>>>>>> Nelson
	}
	else
	{
		do
		{
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				perror("waitpid");
				return -1;
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 0;
}
