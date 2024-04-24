#include "simple_shell.h"

/**
 * main - print prompt, handle EOF, read file_stream
 * @argc: arg count (not needed)
 * @argv: argv for command
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	char *s = NULL;
	size_t buffer_size = 0;
	ssize_t file_stream = 0;
	char *name = argv[0];

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "simple_shell ", 13);
		file_stream = getline(&s, &buffer_size, stdin);
		if (file_stream == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			break;
		}

		if (s[file_stream - 1] == '\n')
			s[file_stream - 1] = '\0';
		if (*s == '\0')
			continue;
		if (cmd_read(s, file_stream, name) == 2)
		{
			free(s);
			exit(EXIT_SUCCESS);
		}
	}
	free(s);
	s = NULL;
	return (0);
}

/**
 * cmd_read - handles command line and tokenizes it
 *@s: string
 *@file_stream: getline input
 *@name: name of the command
 * Return: 0
 */
int cmd_read(char *s, size_t __attribute__((unused)) file_stream, char *name)
{
	char *token = NULL;
	char *cmd_arr[100];
	int i;

	if (s == NULL)
		return (0);

	if (strcmp(s, "exit") == 0)
		return (2);

	if (strcmp(s, "env") == 0)
		return (_printenv());

	token = strtok(s, " "), i = 0;
	while (token)
	{
		cmd_arr[i++] = token;
		token = strtok(NULL, " ");
	}
	if (i == 0)
		return (0);

	cmd_arr[i] = NULL;
	return (call_command(cmd_arr, name));
}

/**
 * print_not_found - prints when cmd is not found in path
 *
 * @cmd: a string provided by the stdin
 * @name: name of the command
 */
void print_not_found(char *cmd, char *name)
{
	fprintf(stderr, "%s: %s: command not found\n", name, cmd);
}

/**
 * call_command - calls cmd, forks, execve
 *
 * @cmd_arr: a string provided by the stdin
 * @name: name of the command
 * Return: 0
 */
int call_command(char *cmd_arr[], char *name)
{
	char *cmd = cmd_arr[0];
	struct stat buf;
	char *exe_path_str = NULL;
	int result;

	if (cmd[0] == '/' || strncmp(cmd, "./", 2) == 0 ||
		strcmp(_getenv("PATH"), "") == 0)
	{
		if (stat(cmd, &buf) == 0)
		{
			result = execute_command(cmd_arr, name);
			return (result);
		}
		else
		{
			print_not_found(cmd, name);
			return (3);
		}
	}

	exe_path_str = pathfinder(cmd);
	if (exe_path_str == NULL)
	{
		print_not_found(cmd, name);
		return (3);
	}

	cmd_arr[0] = exe_path_str;
	result = execute_command(cmd_arr, name);
	free(exe_path_str);
	return (result);
}

/**
 * execute_command - executes the command
 *
 * @cmd_arr: a string provided by the stdin
 * @name: name of the command
 * Return: 0
 */
int execute_command(char *cmd_arr[], char *name)
{
	pid_t is_child;
	int status;

	is_child = fork();
	if (is_child < 0)
	{
		perror("Error:");
		return (-1);
	}
	if (is_child > 0)
	{
		wait(&status);
	}
	else if (is_child == 0)
	{
		execve(cmd_arr[0], cmd_arr, environ);
		{
			perror(name);
			exit(1);
		}
	}
	return (0);
}
