#include "main.h"

/**
 * _exec - executes a command given arguments and env and handles errors
 * @args: the arguments for the command
 * @cmd: given command string
 *
 * Return: status
 */
int _exec(char **args, char *cmd)
{
	pid_t child_pid = 0;
	int status = 0;
	int ret_value = 0;

	child_pid = fork();
	if (child_pid == 0)
	{
		ret_value = execve(args[0], args, environ);
		if (ret_value == -1)
		{
			fprintf(stderr, "./hsh:  %s: not found\n", strtok(cmd, " "));
			exit(127);
		}
		exit(EXIT_SUCCESS);
	}
	else if (child_pid > 0)
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
	}
	else
	{
		perror("fork process failed.");
		return (status);
	}

	return (status);
}
