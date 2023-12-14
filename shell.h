#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

int _shell(int argc, char **argv);
char **_tokenize(char *src, char *delim, int *num_token);
int execmd(char **argv);
char ** alloctok(char *input, char **tokens, int token_num);
void freeMem(char *buf, char **tokens, char **argv);
char* _strchr(const char* str, int character);
int _strcmp(char *s1, char *s2);
char *_getenv(char *command);
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
char *_getloc(char *command);
char *_strdup(char *str);
char *_strtok(char *str, const char *delim);

#endif
