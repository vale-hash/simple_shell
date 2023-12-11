#include "shell.h"
/**
 * alloctok - Function to allocate tokens
 * @input: the buffer that has been inputed
 * @tokens: space for the individual string parsed
 * @token_num: number of tokens
 * @argv: array of arguements
 * Return: returns 0
 */
char **alloctok(char *input, char **tokens, int token_num) {
	char **argv;
	int i,j;

	if (tokens == NULL) {
		free(input);
		return NULL;
	}

	argv = malloc(sizeof(char *) * (token_num + 1));
	if (argv == NULL) {
		perror("Memory allocation failed");
		/* Free allocated tokens and input*/
		for (i = 0; tokens[i] != NULL; i++) {
			free(tokens[i]); /*SUSPECT 1*/
		}
		free(tokens); /*SUSPECT 2*/
		free(input);
		return NULL;
	}

	for (i = 0; i < token_num; i++) {
		argv[i] = (char *)malloc(strlen(tokens[i]) + 1);
		if (argv[i] == NULL) {
			perror("Memory allocation failed");
			/* Free allocated memory for argv and previously allocated tokens*/
			for (j = 0; j < i; j++) {
				free(argv[j]);
			}
			free(argv);
			for (j = 0; tokens[j] != NULL; j++) {
				free(tokens[j]); /* SUSPECT 3 */
			}
			free(tokens); /* SUSPECT 4 */
			free(input);
			return NULL;
		}
		strcpy(argv[i], tokens[i]);
	}
	argv[token_num] = NULL;

	/* Free allocated tokens and input (no longer needed)*/
	for (i = 0; tokens[i] != NULL; i++) {
		free(tokens[i]);
	}
	free(tokens);

	return (argv);
}

