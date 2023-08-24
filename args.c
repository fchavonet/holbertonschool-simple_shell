#include "main.h"

/**
 * build_args - initialize an array of strings containing arguments
 * @cmd: given command string
 *
 * Return: pointer to created array of args
 */
char **build_args(char *cmd)
{
	unsigned int i = 0;
	unsigned int count = 0;
	char *token;
	char **args = NULL;

	/* move the \0 replacement here */
	while (cmd[i] != '\0')
	{
		if (cmd[i] == ' ')
			count++;
		i++;
	}
	/* ne pas oublier d'ajouter 1 au count si on ajoute --color=auto */
	args = malloc(sizeof(char *) * (count + 2));
	if (args == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	if (count > 0)
	{
		token = strtok(cmd, " ");
		i = 0;
		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
	}
	else
	{
		args[0] = cmd;
		i = 1;
	}
	args[i] = NULL;
	return (args);
}

/**
 * build_cmd_path - builds path of the executable from given command string
 * @cmd: given command string
 * @path: raw PATH string
 *
 * Return: built path string
 */
char *build_cmd_path(char *cmd, char *path)
{
	char *path_copy = NULL;
	char *token = NULL;
	char *path_dirs = NULL;
	char *built_path = NULL;

	if (path == NULL)
		return (NULL);
	path_copy = strdup(path);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		path_dirs = strdup(token);
		built_path = malloc(strlen(path_dirs) + strlen(cmd) + 2);
		if (built_path == NULL)
		{
			free(path_dirs);
			perror("malloc failed.");
			exit(EXIT_FAILURE);
		}
		sprintf(built_path, "%s/%s", path_dirs, cmd);
		free(path_dirs);
		if (access(built_path, X_OK) == 0)
		{
			free(path_copy);
			return (built_path);
		}
		free(built_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
