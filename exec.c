#include "main.h"

/**
 * _exec - executes a command given arguments and env and handles errors
 * @args: the arguments for the command
 *
 * Return: TODO
 */
int _exec(char **args)
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
			fprintf(stderr, "./hsh: No such file or directory\n");
		}
		exit(EXIT_SUCCESS);
	}
	else if (child_pid > 0)
	{
		wait(&status);
	}
	else
	{
		perror("execve process failed.");
	}

	return (ret_value);
}