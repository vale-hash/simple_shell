#include "shell.h"

char **_tokenize(char *src, char *delim, int *num_token) {
    char **tokens = NULL;
    char *token;
    char *str;
    int count = 0;

    str = malloc(sizeof(char) * (strlen(src) + 1));
    if (str == NULL) {
        exit(EXIT_FAILURE);
    }
    strcpy(str, src);

    token = strtok(str, delim);
    while (token != NULL) {
        count++;
        token = strtok(NULL, delim);
    }

    tokens = malloc(sizeof(char *) * (count + 1));
    if (tokens == NULL) {
        free(str);
        exit(EXIT_FAILURE);
    }

    strcpy(str, src);
    token = strtok(str, delim);
    count = 0;
    while (token != NULL) {
        tokens[count] = malloc(sizeof(char) * (strlen(token) + 1));
        if (tokens[count] == NULL) {
            free(str);
            exit(EXIT_FAILURE);
        }
        strcpy(tokens[count], token);
        count++;
        token = strtok(NULL, delim);
    }
    tokens[count] = NULL;
    *num_token = count;

    free(str);
    return tokens;
}
