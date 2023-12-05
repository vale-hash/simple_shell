/**
 *main - a program that mimics the bash shell
 * @argv: total number of arguments passed in the shell
 * @argc : poitter to an array of arguemnts passed in the shell
 * Return: argv
 */
#include "shell.h"
int main(int argv, char **argc)
{
	char *buf;
	ssize_t buf_size;
	size_t n;
	char *prompt;
	bool p;
	/*while statement to keep the program running*/
	n = 10;
	p = true;
	while (p == true)
	{
		prompt = "Bshell#";
		write(1, prompt, 7);
		buf_size = getline(&buf, &n, stdin);
		if (buf_size == -1)
		{
			return (-1);
		}

	}
	free(buf);
	return (0);
}