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
		/* think to free args[i] */
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

	/* j'ai tokenisé ici directement */
	token = strtok(cmd, " ");

	while (token != NULL)
	{
		args[i] = strdup(token);
		token = strtok(NULL, " ");

		/* j'ai incrémenté i, on l'avais oublié je pense */
		i++;
	}

	/* j'ai ajouté lme return de args et un ull à la fin de args */
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
	unsigned int i = 0;
	char *path_dirs[1024];
	path_copy = strdup(path);
	char *built_path = NULL;

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		path_dirs[i] = strdup(token);
		i++;
		token = strtok(NULL, ":");
	}
	path_dirs[i] = NULL;

	for (i = 0; path_dirs[i] != NULL; i++)
	{
		path_dirs[i] = strcat(path_dirs[i], "/");
		path_dirs[i] = strcat(path_dirs[i], cmd);
		printf("[%s]\t", path_dirs[i]);
		if(access(path_dirs[i], X_OK) == 0)
		{
			printf("Found you ! ");
			printf("%s\n", path_dirs[i]);
			built_path = strdup(path_dirs[i]);
			for(i = 0; path_dirs[i] != NULL; i++)
			{
				free(path_dirs[i]);
			}
			free(path_copy);
			printf("Returning [%s]\n", built_path);
			return (built_path);
		}
	}
	return (built_path);
}

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
	ssize_t getline_result = 0;
	int execve_result = 0;
	pid_t child_pid = 0;
	int status = 0;
	char **args = NULL;

	while (1)
	{
		printf("$ ");
		getline_result = getline(&cmd, &max_cmd_length, stdin);
		if (getline_result == EOF)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		/* ici j'ai remplacé token par cmd pour que exit remarche (j'ai testé au pif, et ça marche :s */
		if (strcmp(cmd, "exit\n") == 0)
		{
			free_buffers(user_input, cmd, args);
			exit(EXIT_SUCCESS);
		}

		/* j'ai remis ça pour supprimer le saut de ligne qu'on avaiot enlevé, sinon ça marchait pas, c'est chat GPT qui m'a résolu ce soucis */
		cmd[strlen(cmd) - 1] = '\0';

		args = build_args(cmd);
		//free(args[0]);
		args[0] = build_cmd_path(cmd, getenv("PATH"));
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
