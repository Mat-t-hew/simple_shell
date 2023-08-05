#include "simple.h"

/**
 * ev__cd - Execute the env command
 *
 * @cmd: Command arguments
 *
 * Return: void
 */

void ev__cd(char **cmd)
{
	extern char **environ;
	int e;

	for (e = 0; environ[e] != NULL; e++)
		;

	for (e = e - 1; e >= 0; e--)
		printf("%s\n", environ[e]);

	execve("/usr/bin/env", cmd, environ);

	perror("execve");
}
