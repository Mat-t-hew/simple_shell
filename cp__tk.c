#include "simple.h"

void cp__tk(char **t_k_a)
{
	int j;
	for(j=0; t_k_a[j] !=NULL; j++)
	{
		free(t_k_a[j]);
	}
	free(t_k_a);
}
