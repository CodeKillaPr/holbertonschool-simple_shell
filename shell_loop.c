#include "shell.h"

/**
 * shell_loop - Función para iniciar el bucle de la shell
 * Return: nada
 */
void shell_loop(void)
{
	char command[MAX_COMMAND_LENGTH];
	char **args;

	while (1)
	{
		printf("simple_shell$ ");
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			perror("fgets");
			exit(EXIT_FAILURE);
		}

		args = parse_line(command);
		if (args == NULL)
		{
			continue;
		}

		execute_command(args);

		free(args);
	}
}
