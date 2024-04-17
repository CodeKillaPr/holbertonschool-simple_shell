#include "shell.h"
/**
 * find_command - Función para buscar un comando en el PATH
 * @command: Comando a buscar
 * Return: Ruta completa del comando o NULL si no se encuentra
 */
char *find_command(char *command)
{
	char *path, *token, *path_copy;
	struct stat st;
	char *full_path;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		full_path = strcat(token, "/");
		full_path = strcat(full_path, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
