#include "simple.h"

/**
 * display - shows contents of command-line arguments & environment variables
 *
 * @env: pointers representing the environment variables
 *
 * Return: void
 */

void display(char **env)
{
	/*char *string = NULL;*/
	char *ln = NULL;
	size_t x = 0;
	ssize_t nm_cr;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($)");

		nm_cr = getline(&ln, &x, stdin);
		/*nm_cr = gt__ln(&ln, &x, stdin);*/

		if (nm_cr == -1)
		{
			free(ln);
			exit(EXIT_SUCCESS);
		}

		rm__nw(ln);

		if (strcmp(ln, "exit") == 0)
		{
			bt__et();
			continue;
		}
		else
		{
			ex__cm(ln, env);
		}
		/*free(ln);*/
	}
}
/*Matthew*/
