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
 * handle_special_cmd - handles special commands like env, exit
 * @args: given array of argument strings
 * @user_input: given user input (string input from the user)
 *
 * Return: 0 to continue in main
 */
int handle_special_cmd(char **args, char *user_input)
{
	if (strcmp(args[0], "env") == 0)
	{
		print_env(environ);
		free(args);
		return (0);
	}
	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(user_input);
		exit(EXIT_SUCCESS);
	}
	return (1);
}
