

#include "shell.h"

void execmd(char **argv)
{

    int comm;
    char *command = NULL;

    if(argv != NULL)
    {
    command = argv[0];
    }

    comm = execve(command,argv,NULL);
    if (comm == -1){
        perror("error");
    }


}

