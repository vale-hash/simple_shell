#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int _shell(int argc, char **argv);
char **_tokenize(char *src, char *delim, int *num_token);
int execmd(char **argv);
char ** alloctok(char *input, char **tokens, int token_num);
void freeMem(char *buf, char **tokens, char **argv);
char* _strchr(const char* str, int character);
#endif
