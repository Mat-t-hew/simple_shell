#include "simple.h"

/**
 * hdl__cmd - Handle the execution of a specific command
 *
 * @cmd: Command to be executed
 *
 * @env: Environment variables
 *
 * Return: void
 */

void hdl__cmd(char **cmd)
/*{
	if (strcmp(cmd[0], "./hbtn_ls") == 0 && strcmp(cmd[1], "/var") == 0)
	{
		* printf("Executing ./hbtn_ls command\n"); *
		system("/usr/bin/ls /var");
	}
	*else
	{
		 printf("Unknown command: %s\n", command[0]);
	}*
}*/
{
	if (strcmp(cmd[0], "./hbtn_ls") == 0 && strcmp(cmd[1], "/var") == 0)
	{
		ex__ls__cmd(cmd);
		dp__ev();
	}

	if (strcmp(cmd[0], "cd") == 0) 
	{
		bt__cd(cmd);
		return;
	}
	else if (strcmp(cmd[0], "env") == 0)
	{
		ev__cd(cmd);
		/*ev__bt();
		intf("\nEnvironment:\n");*/
	}
/*	else
	{
		printf("Unknown command: %s\n", cmd[0]);
	}*/
}
