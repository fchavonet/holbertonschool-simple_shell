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

	while (cmd[i] != '\0')
	{
		if (cmd[i] == ' ')
		{
			count++;
		}
		i++;
	}

	/* ne pas oublier d'ajouter 1 au count pour le malloc si on ajoute --color=auto */
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

/**
 * main - temporary, for testing purposes
 *
 * Return: 0
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env)
{
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
			free(cmd);
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		if (strcmp(cmd, "exit\n") == 0)
		{
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		cmd[strlen(cmd) - 1] = '\0';
		args = build_args(cmd);

		if (access(args[0], X_OK) != 0)
		{
			args[0] = build_cmd_path(cmd, getenv("PATH"));
		}
		else
		{
			args[0] = strdup(args[0]);
		}

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
		free(args[0]);
		free(args);
	}
	return (0);
}
