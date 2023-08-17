#include "main.h"
/**
 * free_buffers - frees allocated variables
 *
 * Return: 0
*/
int free_buffers(char *user_input, char *cmd)
{
	if (user_input != NULL)
	{
		free(user_input);
	}
	if (cmd != NULL)
	{
		free(cmd);
	}
	return (0);
}

// /**
//  * execute_cmd - executes a command from the given path string
//  * @path: given path string
//  *
//  * Return: execve return value
// */
// int execute_cmd()

/**
 * main - temporary, for testing purposes
 *
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	size_t max_cmd_length = 4096;
	//atoi(getenv("ARG_MAX"));
	char *user_input = NULL;
	char *cmd = NULL;
	char *token = NULL;
	ssize_t getline_result = 0;
	int execve_result = 0;
	pid_t child_pid = 0;
	int status = 0;

	char *tmp_av[2];
	tmp_av[0] = "-1";
	tmp_av[1] = NULL;

	while (1)
	{
		printf("$ ");
		getline_result = getline(&cmd, &max_cmd_length, stdin);
		if (getline_result == -1)
		{
			perror("getline process failed.");
			exit(EXIT_FAILURE);
		}
		else if (getline_result == EOF)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		token = strtok(cmd, " ");
		if (strcmp(token, "exit") == 0)
		{
			free_buffers(user_input, cmd);
			exit(EXIT_SUCCESS);
		}
		child_pid = fork();
		if (child_pid == 0)
		{
			execve_result = execve(token, tmp_av, env);
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
	}
	free_buffers(user_input, cmd);
	return (0);
}
