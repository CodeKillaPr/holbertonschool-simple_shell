#include "shell.h"

/**
 * shell_loop - Función para iniciar el bucle de la shell
 * Return: nada
 */
void shell_loop(void)
{
	char *line;
	char **args;
	int status;

	do
	{
		printf("simple_shell$ ");
		line = read_line();
		args = parse_line(line);
		if (args != NULL && args[0] != NULL)
		{
			status = execute_command(args);
		}
		else
		{
			status = 1;
		}

		free(line);
		free(args);
	} while (status);
}
