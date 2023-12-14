#include "shell.h"
/**
 * _getenv - function to get the envriment varaible
 * @command :the commnad we are looking ofr
 * Return: returns the path
 */

char *_getenv(char *command)
{
	int i;
	char *path;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strcmp(environ[i], command) == 0)
		{
			path = malloc(sizeof(char *) * strlen(environ[i]));/*remember to free*/
			if (path != NULL)
			{
				strcpy(path, environ[i] + strlen(command) + 1);
			}
			else
			{
				free(path);
			}
		}
	}
	return (path);
}
