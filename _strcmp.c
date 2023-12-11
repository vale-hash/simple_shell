#include "shell.h"

/**
 * _strcmp - Function that compares two strings.
 * @s1: type str
 * @s2: type str
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
int x;

	for (x = 0; s1[x] != '\0' && s2[x] != '\0'; x++)
	{
		if (s1[x] != s2[x])
		return (s1[x] - s2[x]);
	}
	return (0);
}
