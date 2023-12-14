#include "shell.h"
/**
 * _getloc - function to get the path location
 * @command: the command passed in buf
 * Return: returns the file path if it exists
 */
char *_getloc(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		path_copy = _strdup(path);
		command_length = strlen(command);

		path_token = _strtok(path_copy, ":");
		/*if (stat(command, &buffer) == 0)*/
			/*return (command);*/
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			_strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				free(path);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = _strtok(NULL, ":"); }
		}
		if (stat(command, &buffer) == 0)
			return (command);
		free(path_copy);
	}
	file_path = malloc(strlen(command) + 1);
	_strcpy(file_path, command);
	free(path);
	return (file_path);
}

