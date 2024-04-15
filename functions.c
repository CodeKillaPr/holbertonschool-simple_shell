#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string to be returned
 * Return: a string length
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: int less, equal or greater than 0 if s1 < s2, s1 == s2 or s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}

	else
	{
		return (*s1 - *s2);
	}
}

/**
 * _getenv - gets value of env var
 * @name: name of variable in env
 *
 * Return: NULL or value of env var
 */
char *_getenv(const char *name)
{
	char **ePtr;		 /* pointer to environ */
	char *cPtr;			 /* pointer to character in string in environ */
	const char *namePtr; /*pointer to name we received */

	for (ePtr = environ; *ePtr != NULL; ePtr++)
	{ /* compares name to environment variable name */
		for (cPtr = *ePtr, namePtr = name; *cPtr == *namePtr; cPtr++, namePtr++)
		{ /* makes sure to only compare name to env var name (not its value) */
			if (*cPtr == '=')
				break;
		}
		if ((*cPtr == '=') && (*namePtr == '\0'))
			return (cPtr + 1);
	}
	return (NULL);
}

/**
 * free_grid - Function that fress a 2 dimensional grid
 * previously created by your alloc_grid.
 * @grid: First int
 *
 * Return: void
 */
void free_grid(char **grid)
{
	int i = 0;

	while (grid[i] != NULL && grid[i + 1] != NULL)
	{
		printf("%s\n", grid[i]);
		free(grid[i]);
		i++;
	}
	free(grid);
}

/**
 * av_error - prints perror with av[0]
 * @av: argument vector
 * Return: VOID
 */
void av_error(char **av)
{
	perror(av[0]);
}
