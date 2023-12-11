#include "shell.h"

void freeMem(char *buf, char **tokens, char **argv){
    int i;

    if (buf != NULL) {
        free(buf);
    }

    if (tokens != NULL) {
        for (i = 0; tokens[i] != NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }

    if (argv != NULL) {
        for (i = 0; argv[i] != NULL; i++) {
            free(argv[i]);
        }
        free(argv);
    }
}
