#include "simple.h"

/**
 * rm__nw - remove newline character from a string
 *
 * @string: input string
 *
 * Return: void
 */

void rm__nw(char *string)
{
	int a = 0;

	while (string[a])
	{
		if (string[a] == '\n')
			string[a] = '\0';
		a++;
	}
}
/*Matthew*/
