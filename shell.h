#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int _shell(int argc, char **argv);
char **_tokenize(char *src, char *delim, int *num_token);
void execmd(char **argv);
#endif
