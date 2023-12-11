/**
 *main - a program that mimics the bash shell
 * @argv: total number of arguments passed in the shell
 * @argc : poitter to an array of arguemnts passed in the shell
 * Return: argv
 */
#include "shell.h"
int main(int argc, char *argv[])
{
	char **tokens, **alloct_res;
	char buf[1024] = "";
	int token_num, i;
	ssize_t buf_size;
	char *prompt, *delim;
	bool p;
	pid_t child;
	(void) argc;
	(void) argv;
	prompt = "(Bshell)# ";
	p = true;
	delim = " \n";
	while (p == true)
	{
		write(1, prompt, 10);
		buf_size = read(STDIN_FILENO, buf, 1024);
		if (buf_size == -1 || buf_size == 0)
			return (-1);
		if (_strcmp(buf, "exit\n") == 0)
			return (-1);
		tokens = _tokenize(buf, delim, &token_num);
		if (tokens == NULL)
		{
			return (-1);
		}
		alloct_res = alloctok(buf, tokens, token_num);
		if (alloct_res == NULL)
		{
			free(alloct_res);
			free(tokens);
			return (-1);
		}
		child = fork();
		if (child == 0)
		{
			if (execmd(alloct_res) == -1)
			{
				free(alloct_res);
			}
		}
		wait(NULL);
		for (i = 0; i < token_num; i++)
			free(alloct_res[i]);
		free(alloct_res);
	}
	return (0);
}
