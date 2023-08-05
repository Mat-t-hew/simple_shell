#include "simple.h"

/**
 * exec__cm - execute a command with arguments
 *
 * @argc: number of arguments
 *
 * @argv: array of arguments
 *
 * @env: environment variables
 *
 * Return: number of arguments
 */

int exec__cm(int argc, char **argv, char **env)
{
	pid_t pid = -1;
	int c;

	if (argv[0] == NULL)
	{
		return (-1);
	}
/*	else if (strcmp(argv[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
*/
	for (c = 0; c < argc; c++)
	{
		if (argv[c] == NULL)
		{
			break;
		}
	}

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		int status;

		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}

	return (0);
}
/*Matthew*/
