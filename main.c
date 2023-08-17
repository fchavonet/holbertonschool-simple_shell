#include "main.h"

/**
 * free_buffers - frees allocated variables
 *
 * Return: 0
 */
int free_buffers(char *user_input, char *cmd, char **args)
{
	if (user_input != NULL)
	{
		free(user_input);
	}
	if (cmd != NULL)
	{
		free(cmd);
	}
	if (args != NULL)
	{
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
	unsigned int count = 1;
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

	args = malloc(sizeof(char *) * count);
	if (args == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	i = 0;

	/* j'ai tokenisé ici directement */
	token = strtok(cmd, " ");

	while (token != NULL)
	{
		args[i] = strdup(token);
		token = strtok(NULL, " ");
		/* j'ai incrémenté i, on l'avais oublié je pense */
		i++;
	}

	/* j'ai ajouté lme return de args */
	return (args);
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
	// atoi(getenv("ARG_MAX"));
	char *user_input = NULL;
	char *cmd = NULL;
	// char *token = NULL;
	ssize_t getline_result = 0;
	int execve_result = 0;
	pid_t child_pid = 0;
	int status = 0;
	char **args = NULL;

	// char *tmp_av[2];
	// tmp_av[0] = "-1";
	// tmp_av[1] = NULL;

	while (1)
	{
		printf("$ ");
		getline_result = getline(&cmd, &max_cmd_length, stdin);
		if (getline_result == EOF)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		/* token = strtok(cmd, " ");
		   token[strlen(token) - 1] = '\0';
		   printf("[%s] is %lu chars long.\n", cmd, strlen(cmd)); */

		/* ici j'ai remplacé token par cmd pour que exit remarche (j'ai testé au pif, et ça marche :s */
		if (strcmp(cmd, "exit\n") == 0)
		{
			free_buffers(user_input, cmd, args);
			exit(EXIT_SUCCESS);
		}

		/* j'ai remis ça pour supprimer le saut de ligne qu'on avaiot enlevé, sinon ça marchait pas, c'est chat GPT qui m'a résolu ce soucis */
		cmd[strlen(cmd) - 1] = '\0';

		args = build_args(cmd);
		child_pid = fork();
		if (child_pid == 0)
		{
			/* ici j'ai remplacé token par args[0] vu que j'ai tokenisé dans la fonction */
			execve_result = execve(args[0], args, env);
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
	free_buffers(user_input, cmd, args);
	return (0);
}
