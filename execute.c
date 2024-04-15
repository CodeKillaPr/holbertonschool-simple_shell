#include "main.h"

/**
 * execute_child - executes a command
 * @tokens: list of commands to be executed
 * Return: 0
 */
int execute_child(char **tokens)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			free_grid(tokens);
			perror("not found");
			return (-1);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&status);
	}

	return (0);
}
