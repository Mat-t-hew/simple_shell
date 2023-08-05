#include "simple.h"

/**
 * pr__in - parse input string into arguments
 *
 * @in: input string
 *
 * @argv: array of arguments
 *
 * @env: environment variable
 *
 * Return: number of arguments
 */

int pr__in(char *in, char **argv, char **env)
{
	int b = 0;

	argv[b] = strtok(in, " ");

	while (argv[b])
	{
		b++;
		argv[b] = strtok(NULL, " ");
	}

	if (argv[0] == NULL)
	{
		return (-1);
	}

	return (exec__cm(b, argv, env));
}
/*Matthew*/
