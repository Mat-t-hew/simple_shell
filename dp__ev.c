#include "simple.h"

/**
 * dp__ev - Display the current environment variables after every command
 *
 * Return: void
 */

void dp__ev()
{
	extern char **environ;
	int E;

	printf("Environment:\n");
	for (E = 0; environ[E] != NULL; E++)
	{
		printf("%s\n", environ[E]);
	}
}
