#include "simple.h"

void bt__cd(char **args) 
{
	char *directory = args[1];
	/*char *cwd = NULL;
	char *oldpwd = NULL;*/
	char cwd[PATH_MAX];

	if (directory == NULL) 
	{
		directory = getenv("HOME");
		if (directory == NULL)
			{
			/*fprintf(stderr, "cd: No home directory found\n");*/
			return;
		}
	}

	else if (strcmp(directory, "-") == 0)
	{
	directory = getenv("OLDPWD");
	if (directory == NULL)
	{
		/*fprintf(stderr, "cd: No previous directory found\n");*/
		return;
	}
	}
	/*printf("%s\n", directory);*/
	

	/*cwd = malloc(PATH_MAX);
	oldpwd = malloc(PATH_MAX);
	
	if (cwd == NULL || oldpwd == NULL)
	{
		perror("malloc");
		free(cwd);
		free(oldpwd);
		return;
	}

	if (getcwd(oldpwd, PATH_MAX) == NULL)
		{
		perror("getcwd");
		free(cwd);
		free(oldpwd);
		return;
		}*/

	if (chdir(directory) !=0)
	{
		/*perror("chdir");*/
		fprintf(stderr, "./hsh: 1: cd: can't cd to %s\n", directory);
		 return;
		/*free(cwd);
		free(oldpwd);*/
		/*return;*/
	}

	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		perror("getcwd");
		/*free(cwd);
		free(oldpwd);*/
		return;
	}

	if(setenv("PWD", cwd, 1) != 0)
		{
			perror("setenv");
			/*free(cwd);
			free(oldpwd);*/
			return;
		}
		if (setenv("OLDPWD", directory, 1) != 0)
		{
			perror("setenv");
			/*free(cwd);
			free(oldpwd);*/
			return;
		}
		
	/*free(cwd);
	free(oldpwd);*/
}
 
