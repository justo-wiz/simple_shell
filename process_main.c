#include "process_shell.h"
/**
 * main - Beginning of the program.
 * @ad: Command line args count
 * @argv: Argument vector
 * @env: Environmental variables
 * Return: 0 on success
 */
int main(int ad, char **argv, char **env)
{
	char *lnptr = NULL, *lnptr_cpy = NULL, *tken, **args, *prompt = "$ ", *p_id;
	size_t siz = 0;
	ssize_t r_char;
	const char *delim = " \n";
	int x, md = isatty(0), n_tokens = 0;
	pid_t ppid;
	(void)ad;
	(void)argv;

	while (1)
	{
		if (md == 1)
			_printst(prompt);
		r_char = getline(&lnptr, &siz, stdin);
		if (r_char == -1)
		{
			if (feof(stdin))
			{
				_printst("\n");
				free(lnptr);
				exit(0);
			}
		}
		handle_comment(lnptr);
		p_id = strstr(lnptr, "$$");
		if (p_id != NULL)
		{
			ppid = getppid();
			printf("%u\n", ppid);
		}
		/* args = split_ln(lnptr);*/

		/* lnptr_cpy = malloc(sizeof(char) * (r_char +1)); */
		lnptr_cpy = strdup(lnptr);
		if (lnptr_cpy == NULL)
		{
			perror("Ooops! Memomry alloc Error!");
			free(lnptr_cpy);
			exit(0);
		}
		/* strcpy(lnptr_cpy, lnptr);*/
		tken = strtok(lnptr, delim);
		while (tken != NULL)
		{
			n_tokens++;
			tken = strtok(NULL, delim);
		}
		n_tokens++;
		args = malloc(sizeof(char *) * n_tokens);
		tken = strtok(lnptr_cpy, delim);
		for (x = 0; tken != NULL; x++)
		{
			args[x] = malloc(sizeof(char) * strlen(tken));
			strcpy(args[x], tken);
			tken = strtok(NULL, delim);
		}
		process_exe(args, env);
	}
	free(lnptr_cpy);
	free(lnptr);
	free_args(args);
	return (0);
}
