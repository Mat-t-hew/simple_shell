#include "simple.h"

/**
 * tk__nz - Tokenizes input string into an array of tokens
 *
 * @in: input string
 *
 * @t_k_a: array of tokens to store the result
 *
 * Return: Always t
 */

int tk__nz(char *in, char **t_k_a)
{
	char *tk;
	int t = 0;
	int i;

	tk = strtok(in, " \t\n");
	while (tk != NULL)
	{
	 t_k_a[t] = strdup(tk);
	 if (t_k_a[t] == NULL)
	 {
		 for (i = 0; i < t; i++)
		 {
			 free(t_k_a[i]);
		 }
		 cp__tk(t_k_a);
		 return -1;
	 }
	 t++;
	 tk = strtok(NULL, " \t\n");
	}
		t_k_a[t] = NULL;
		return (t);
}
