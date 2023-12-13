#include "shell.h"
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
				_strcpy(path, environ[i] + strlen(command) + 1);
			}
			else
			{
				free(path);
			}
		}
	}
	return (path);
}
