#include "simple.h"

/**
 * fr__ev - Free the allocated environment variable strings
 *
 * @envp: Environment variable array
 *
 * Return: void
 */

void fr__ev(char **envp)
{
	int e;
	for (e = 0; envp[e] != NULL; e++)
		free(envp[e]);
}
