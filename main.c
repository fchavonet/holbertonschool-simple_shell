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

/**
 * main - temporary, for testing purposes
 *
 * Return: 0
 */
int main(void)
{
	size_t max_cmd_length = 1024;
	//atoi(getenv("ARG_MAX"));
	char *user_input = NULL;
	char *cmd = NULL;
	char *token = NULL;

	// user_input = malloc(sizeof(char) * max_cmd_length);
	// cmd = malloc(sizeof(char) * max_cmd_length);

	while (1)
	{
		printf("$ ");
		if (getline(&cmd, &max_cmd_length, stdin) == 0)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}

		if (strncmp(cmd, "exit", 4) == 0)
		{
			free_buffers(user_input, cmd);
			exit(EXIT_SUCCESS);
		}
		token = strtok(cmd, " ");
		// while (token != NULL)
		// {
		// }
		printf("Token : %s\n", token);
	}
	free_buffers(user_input, cmd);
	return (0);
}
