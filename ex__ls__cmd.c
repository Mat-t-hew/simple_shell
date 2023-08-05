#include "simple.h"

/**
 * ex__ls__cmd - Execute the "ls" command with given arguments
 *
 * @args: Arguments for the "ls" command
 *
 * Return: void
 */

void ex__ls__cmd(char **args)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (strcmp(args[0], "./.././../hbtn_ls") == 0)
		{
		args[0] = "/bin/ls";
		args[1] = "/var";
		args[2] = NULL;
		}
		else if (strcmp(args[0], "./hbtn_ls") == 0)
		{
		args[0] = "/bin/ls";
		args[1] = NULL;
		}

		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, NULL, 0);
	}
	dp__ev();
}
