/**
 *main - a program that mimics the bash shell
 * @argv: total number of arguments passed in the shell
 * @argc : poitter to an array of arguemnts passed in the shell
 * Return: argv
 */
#include "shell.h"
int main(int argc, char *argv[])
{	char **tokens;
	char buf[1024] = " ";
	int token_num, i;
	ssize_t buf_size;
	char *prompt, *delim, *real_path;
	bool p;
	pid_t child;
	(void) argc;
	prompt = "(Bshell)# ";
	p = true;
	delim = " \n";
	while (p == true)
	{
		write(1, prompt, 10);
		real_path = NULL;
		tokens = NULL;
		buf_size = read(STDIN_FILENO, buf, 1024);
		if (buf_size == -1 || buf_size == 0)
			return (-1);
		for (i = 0; buf[i] != '\n'; i++)
			;
		buf[i + 1] = '\0';
		if (_strcmp(buf, "exit\n") == 0)
			return (-1);
		tokens = _tokenize(buf, delim, &token_num);
		if (tokens == NULL)
			return (-1);
		real_path = _getloc(tokens[0]);
		if (strcmp(real_path, tokens[0]) != 0 || real_path[0] == '/')
		{child = fork();
			if (child == 0)
				if (execve(real_path, tokens, NULL) == -1)
					perror(argv[0]);
			wait(NULL); }
		else
		{ perror(argv[0]); }
		for (i = 0; i < token_num; i++)
		{	tokens[i] = 0; }
		free(tokens);
		free(real_path); }
	return (0);
}
