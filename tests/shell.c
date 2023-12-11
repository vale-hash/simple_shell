/**
 *main - a program that mimics the bash shell
 * @argv: total number of arguments passed in the shell
 * @argc : poitter to an array of arguemnts passed in the shell
 * Return: argv
 */
#include "shell.h"
int main(int argc, char **argv)
{
	char **tokens;
	char *buf;
	int token_num;
	ssize_t buf_size;
	size_t n;
	char *prompt;
	bool p;
	char *delim;
	int i;
	char **alloct_res;
	pid_t child;
	(void) argc;
	buf = NULL;
	prompt = "(Bshell)₦";
	p = true;
	delim = " \n";
	while (p == true)
	{
		write(1, prompt, 7);
		buf_size = getline(&buf, &n, stdin);
		if (buf_size == -1)
		{
			free(buf);
			return (-1);
		}
		tokens = _tokenize(buf, delim, &token_num);
		if(tokens == NULL)
		{
				free(buf);
				return(-1);
		}
		alloct_res = alloctok(buf, tokens, token_num);
		if (alloct_res == NULL)
		{	free(argv);
			free(buf);
			free(tokens);
			return (-1);
		}

		child = fork();
		if (child == 0)
		{
			if (execmd(alloct_res) == -1)
			{
				free(alloct_res);
			} else
			{
				for (i = 0; i < token_num; i++)
				{
                free(argv[i]);
				}
            free(alloct_res);
        }
		}
		wait(NULL);

        for (i = 0; tokens[i] != NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }
	for(i = token_num; i>=0; i--)
            {
                    free(tokens[i]);
			}
    free(buf);
    return (0);
}

