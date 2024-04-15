#include "main.h"

/**
 * main - simple shell
 *
 * Return: 1
 */
int main(void)
{
	char *user_input;
	char **tokens;
	int x;

	while (1)
	{
		/*prompt*/
		prompt();

		/*receives user input and stores it in user_input*/
		user_input = read_line();

		/* if user types enter, continue prompt */
		if (user_input[0] == '\0')
		{
			free(user_input);
			continue;
		}

		/* tokenizes user_input */
		tokens = tokenize_input(user_input);

		/* if I was given a normal command */
		if (_strcmp(tokens[0], "env") != 0)
			x = execute_child(tokens);

		if (x != 0)
		{
			free(user_input);
			exit(EXIT_FAILURE);
		}

		free(tokens);
		free(user_input);
	}
	return (0);
}

/**
 * prompt - displays prompt and waits for input
 *
 * Return: VOID
 */
void prompt(void)
{
	char *prompt = "simple_shell ";

	write(STDOUT_FILENO, prompt, _strlen(prompt));
}
