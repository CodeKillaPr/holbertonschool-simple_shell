#include "simple_shell.h"
/**
 * pathfinder - Takes PATH string, tokenizes it, then concats with "/" & cmd
 * @cmd: command passed from getline in main
 *
 * Return: new_path for use in cmd_read
 */
char *pathfinder(char *cmd)
{
	char *path = _getenv("PATH");
	char *path_copy = _strdup(path);
	char *path_token = strtok(path_copy, ":");
	struct stat buffer;
	char *full_path = NULL;

	if (cmd[0] == '/')
	{
		if (stat(cmd, &buffer) == 0)
			return _strdup(cmd);
		else
			return NULL;
	}
	while (path_token != NULL)
	{
		full_path = malloc(strlen(path_token) + strlen(cmd) + 2);
		if (full_path == NULL)
		{
			perror("Error: ");
			return NULL;
		}
		sprintf(full_path, "%s/%s", path_token, cmd);

		if (stat(full_path, &buffer) == 0)
		{
			free(path_copy);
			return full_path;
		}
		free(full_path);
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	return NULL;
}
