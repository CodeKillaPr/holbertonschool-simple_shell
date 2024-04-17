#include "shell.h"

/**
 * shell_loop - Función para iniciar el bucle de la shell
 * Return: nada
 */
void shell_loop(void)
{
	char *line;
	char **args;

	while (1)
	{
		printf("simple_shell$ ");
		line = read_line();
		if (line == NULL)
		{
			printf("\n");
			break;
		}

		args = parse_line(line);
		if (args == NULL)
		{
			free(line);
			continue;
		}

		if (execute_command(args) == 0)
		{
			free(line);
			break;
		}

		free(line);
		free(args);
	}
}
