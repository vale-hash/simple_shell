#include "shell.h"
/**
 *_strdup - function that a points to a memory, containing a copy of str
 * @str:string to be copied
 * Return: returns a pointer to a newly allocated space in memory
 */

char *_strdup(char *str)
{
unsigned int i, j;
char *s;
	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != 0; i++)
	{
		/*get the len of str as i*/
	}
	s = malloc((sizeof(char) * i) + 1);
		if (s == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < i ; j++)
	{
		s[j] = str[j];
	}

	return (s);
	free(s);
}
