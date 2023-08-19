#include "main.h"

/**
 * free_buffers - frees allocated variables
 *
 * Return: 0
 */
int free_buffers(char *cmd, char **args)
{
	unsigned int i = 0;
	if (cmd != NULL)
	{
		free(cmd);
	}
	if (args != NULL)
	{
		while (args[i] != NULL)
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
	return (0);
}

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

	while (cmd[i] != '\0')
	{
		if (cmd[i] == ' ')
		{
			count++;
		}
		i++;
	}

	/* ne pas oublier d'ajouter 1 au count pour le malloc si on ajoute --color=auto */
	args = malloc(sizeof(char *) * count + 1);
	if (args == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	i = 0;

	token = strtok(cmd, " ");

	while (token != NULL)
	{
		args[i] = strdup(token);
		token = strtok(NULL, " ");
		i++;
	}

	args[i] = NULL;
	//free(token);
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

	path_copy = strdup(path);
	built_path = malloc(sizeof(char) * 256);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		path_dirs = strdup(token);
		sprintf(built_path, "%s/%s", path_dirs, cmd);
		//free(path_dirs);
		if (access(built_path, X_OK) == 0)
		{
			//free(path_copy);
			return (built_path);
		}
		token = strtok(NULL, ":");
	}
	//free(built_path);
	//free(path_copy);
	return (NULL);
}

/**
 * main - temporary, for testing purposes
 *
 * Return: 0
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env)
{

	int i = 0;
	size_t max_cmd_length = 4096;
	/* atoi(getenv("ARG_MAX")) */
	ssize_t getline_result = 0;
	pid_t child_pid = 0;
	int status = 0;
	char **args = NULL;
	char *cmd = NULL;

	while (1)
	{
		printf("$ ");
		getline_result = getline(&cmd, &max_cmd_length, stdin);
		if (getline_result == EOF)
		{
			//free_buffers(cmd, args);
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		if (strcmp(cmd, "exit\n") == 0)
		{
			//free_buffers(cmd, args);
			exit(EXIT_SUCCESS);
		}

		cmd[strlen(cmd) - 1] = '\0';

		args = build_args(cmd);
		//free(args[0]);
		args[0] = build_cmd_path(cmd, getenv("PATH"));
		child_pid = fork();
		if (child_pid == 0)
		{
			execve(args[0], args, env);
			exit(1);
		}
		else if (child_pid > 0)
		{
			wait(&status);
		}
		else
		{
			perror("execve process failed.");
		}
		if (args != NULL)
		{
			while (args[i] != NULL)
			{
				free(args[i]);
				i++;
			}
			free(args);
		}

	}
	return (0);
}
