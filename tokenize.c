#include "shell.h"
/**
 *_tokenize - function that splits commands to tokens
 * @src:the string to be tokenized
 * @delim: the delimeter used
 * @num_token : the number of tokens
 * Return: returns the tokens
 *
 */
char **_tokenize(char *src, char *delim, int *num_token) 
{
    char **tokens = NULL;
    char *token;
    char *str;
    int count = 0;
    int i ;
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
            for(i = count; i>=0; i--)
            {
                    free(tokens[i]);
            }
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

    /*free tokens[count] in main funciton*/

}
