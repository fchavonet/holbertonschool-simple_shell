#include "main.h"

/**
 * get_current_directory - Function to retrieve the current directory.
 *
 * Return: a pointer to the current directory name,
 *         or the path (~/) if user is in the /root.
 */
char *get_current_directory(void)
{
	static char current_path[4096];
	char *current_directory = NULL;

	getcwd(current_path, sizeof(current_path));
	current_directory = strrchr(current_path, '/');

	if (current_directory)
	{
		return (current_directory);
	}

	return (current_path);
}

/**
 * handle_special_cmd - Handles special commands like env, exit...
 * @args: given array of argument strings.
 * @user_input: given user input (string input from the user).
 * @status: child process status value.
 * @pwd: current directory.
 *
 * Return: 0 to continue in main.
 */
int handle_special_cmd(char **args, char *user_input, int status, char **pwd)
{
	if (strcmp(args[0], "env") == 0)
	{
		print_env(environ);
		free(args);
		return (0);
	}
	if (strcmp(args[0], "exit") == 0 && args[1] == NULL)
	{
		free(args);
		free(user_input);
		exit(status);
	}
	else if (strcmp(args[0], "exit") == 0 && args[1] != NULL)
	{
		return (0);
	}

	if (strcmp(args[0], "taieb") == 0)
	{
		taieb_face();
		free(args);
		return (0);
	}
	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
			chdir(_getenv("HOME="));
		else if (strcmp(args[1], "..") == 0)
			chdir("..");
		else
		{
			if (chdir(args[1]) != 0)
				perror("cd");
		}
		*pwd = get_current_directory();
		free(args);
		return (0);
	}
	return (1);
}
