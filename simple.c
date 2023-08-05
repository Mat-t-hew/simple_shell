#include "simple.h"

/**
 * main - Entry point
 *
 * @ac: inter representing number of command-line arguments
 *
 * @av: array of character pointers representing command-line arguments
 *
 * @env: array of character pointers environment variables
 *
 * Return: Always 0
 */

int main(int ac, char **av, char **env)
{
	if (ac <= 1)
	{
		display(env);
	}

	else
	{
		display(av);
	}
	return (0);
}
/*Matthew*/
