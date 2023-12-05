int main() {
    char input[] = "Hello, world! This is a test string.";
    char delim[] = " ,!.";
    int num_tokens;

    char **tokens = _tokenize(input, delim, &num_tokens);

    printf("Number of tokens: %d\n", num_tokens);
    printf("Tokens:\n");
    for (int i = 0; tokens[i] != NULL; i++) {
        printf("%s\n", tokens[i]);
        free(tokens[i]); // Free each token
    }
    free(tokens); // Free the array of tokens

    return 0;
}
