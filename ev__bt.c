#include "simple.h"

/**
 * ev__bt - Print the current environment variables
 *
 * return: void
 */

void ev__bt()
{
	extern char **environ;
	char *env_var;

	int e;

	for (e = 0; environ[e] != NULL; e++)
	{
		env_var = strtok(environ[e], "=");
		if (env_var != NULL)
		{
		printf("%s\n", env_var);
		}
	}
}
