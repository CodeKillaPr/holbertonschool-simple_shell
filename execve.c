#include "main.h"

/**
 * main - simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *argv[100];
	int argc;
	int status;
	pid_t pid;

	while (1)
	{
		printf("simple_shell ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(0);
		}
		argc = 0;
		argv[argc] = strtok(line, " \n");
		while (argv[argc] != NULL)
		{
			argc++;
			argv[argc] = strtok(NULL, " \n");
		}
		argv[argc] = NULL;
		pid = fork();
		if (pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
