#include "simple_shell.h"
/**
 * _printenv - prints environment like printenv
 *
 * Return: 0
 */
int _printenv(void)
{
	char *s = environ[0];
	int i = 0;

	while (s)
	{
		write(1, s, strlen(s));
		write(1, "\n", 1);
		s = environ[++i];
	}
	return (0);
}
/**
 * _getenv - gets the value of the environment variable name
 * @var: name of the environment variable
 * Return: the value of the environment variable
 */
char *_getenv(char *var)
{
	int i = 0;

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], var, strlen(var)) == 0)
			return (&environ[i][strlen(var)]);
	}
	return (NULL);
}
