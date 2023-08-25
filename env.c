#include "main.h"

/**
 * _getenv - Get the value of an environment variable.
 *
 * @variable_name: the name of the environment variable to get.
 *
 * Return: if a match is found, a pointer to the environment variable,
 *         NULL if there no match.
 */
char *_getenv(const char *variable_name)
{
	unsigned int i = 0;
	size_t variable_name_length = strlen(variable_name);

	if (variable_name == NULL)
	{
		return (NULL);
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], variable_name, variable_name_length) == 0)
		{
			return (environ[i] + variable_name_length);
		}
	}
	
	return (NULL);
}

/**
 * get_username - Function to retrieve the username.
 *
 * Return: a pointer to the username,
 *         or root if their is no username.
 */
char *get_username(void)
{
	char *username = NULL;

	username = _getenv("USER=");

	if (username == NULL)
	{
		username = "root";
	}

	return (username);
}

/**
 * print_env - Print the environment variables.
 *
 * @environ: array os strings containing environment variables.
 *
 */
void print_env(char **environ)
{
	unsigned int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
