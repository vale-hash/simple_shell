

#include "shell.h"

int execmd(char **argv)
{
	int comm;
	char *command = NULL;
	char *real_comm = NULL;

	if (argv != NULL)
	{
		command = argv[0];

		real_comm = _getloc(command);

		comm = execve(real_comm, argv, NULL);
		if (comm == -1)
		{
			perror("error");
			return (-1);
		}
}
return (0);
}
