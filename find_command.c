#include "shell.h"
/**
 * find_command - Función para buscar un comando en el PATH
 * @command: Comando a buscar
 * Return: Ruta completa del comando o NULL si no se encuentra
 */
char *find_command(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, DELIMITER);
	char *full_path = malloc(strlen(dir) + strlen(command) + 2);

	struct stat st;

	if (path == NULL)
	{
		fprintf(stderr, "No se pudo obtener el PATH\n");
		exit(EXIT_FAILURE);
	}

	if (path_copy == NULL)
	{
		fprintf(stderr, "Error de asignación de memoria\n");
		exit(EXIT_FAILURE);
	}

	while (dir != NULL)
	{
		if (full_path == NULL)
		{
			fprintf(stderr, "Error de asignación de memoria\n");
			exit(EXIT_FAILURE);
		}

		sprintf(full_path, "%s/%s", dir, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return full_path;
		}

		free(full_path);
		dir = strtok(NULL, DELIMITER);
	}

	free(path_copy);
	return NULL;
}
