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

	while (*cmd == ' ' || *cmd == '\t')
		cmd++;
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

/* NEW CODE ADDED */

/**
 * print_env - Print the environment variables.
 *
 * @env: array os strings containing environment variables.
 *
 */
void print_env(char **env)
{
	unsigned int i = 0;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}

/** get_curent_directory - Function to retrieve the current directory.
 *
 * Return : a pointer to the current directory name,
 *          or the path (~/) if user is in the /root.
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

	char *current_directory = get_current_directory();

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("\033[36m~%s\033[0m $ ", current_directory);
			fflush(stdout);
		}
		getline_result = getline(&cmd, &max_cmd_length, stdin);
		if (getline_result == EOF)
		{
			free(cmd);
			if (isatty(STDIN_FILENO))
			{
				printf("\n");
			}
			exit(EXIT_SUCCESS);
		}

		cmd[strlen(cmd) - 1] = '\0';
		args = build_args(cmd);
		/* AJOUT DE CODE */
		if (strcmp(args[0], "env") == 0)
		{
			print_env(env);
			free(args);
			continue; /* pour sauter le cycle fork-exec-wait pour env */
		}
		/* FIN AJOUT DE CODE */
		if (strcmp(args[0], "exit") == 0)
		{
			free(args);
			free(cmd);
			exit(EXIT_SUCCESS);
		}

		if (access(args[0], X_OK) != 0)
		{
			args[0] = build_cmd_path(args[0], getenv("PATH"));
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
