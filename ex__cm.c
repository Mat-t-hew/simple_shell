#include "simple.h"

/**
 * ex__cm - execute a command
 *
 * @in: input string
 *
 * @env: environment variables
 *
 * Return: void
 */

void ex__cm(char *in, char **env)
{
	char *argv[MAX_COMMAND];
	pid_t child_pid;
	int status;
	char *path_env;
	char *full_path = NULL;
	char *div;
	int num_tk = tk__nz(in, argv);
	int valid_path_found = 0;

/*	if (pr__in(in, argv, env) == -1 || argv[0] == NULL)        {
                return;
        }
*/
	if (num_tk == 0 || argv[0] == NULL)
	{
		return;
	}
	
	hdl__cmd(argv);

	if (argv[0][0] == '/')
	{
		full_path = argv[0];
		if (access(full_path, X_OK) != 0)
		{
			/*printf("%s: command not found\n", argv[0]);*/
			return;
		}
	}

	else

	{

	path_env = getenv("PATH");
	div = strtok(path_env, ":");

	while (div != NULL && !valid_path_found)
	{
		free(full_path);
		full_path = malloc(strlen(div) + strlen(argv[0]) + 2);
		strcpy(full_path, div);
		strcat(full_path, "/");
		strcat(full_path, argv[0]);

		if (access(full_path, X_OK) == 0)
		{
			valid_path_found = 1;
			/*break;*/
		}

		free(full_path);
		full_path = NULL;
		div = strtok(NULL, ":");
		continue;
	}

	if (full_path == NULL)
	{
		/*printf("%s: command not found\n", argv[0]);*/
		return;
	}
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execve(full_path, argv, env) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		waitpid(child_pid, &status, 0);
	}

	free(full_path);
}
/*Matthew*/
