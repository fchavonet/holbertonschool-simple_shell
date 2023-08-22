#include "main.h"

/**
 * main - temporary, for testing purposes
 *
 * Return: 0
 */
int main(void)
{
	size_t max_cmd_length = 4096;
	ssize_t getline_result = 0;
	char **args = NULL;
	char *user_input = NULL, *cmd = NULL;
	char *current_dir = get_current_directory(), *username = get_username();

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("\033[32m@%s\033[0m:\033[36m%s\033[0m $ ", username, current_dir);
			fflush(stdout);
		}
		getline_result = getline(&user_input, &max_cmd_length, stdin);
		if (getline_result == EOF)
		{
			free(user_input);
			if (isatty(STDIN_FILENO))
				printf("\n");
			exit(EXIT_SUCCESS);
		}
		cmd = user_input;
		while (*cmd == ' ' || *cmd == '\t')
			cmd++;
		if (strcmp(cmd, "\n") == 0)
			continue;
		cmd[strlen(cmd) - 1] = '\0';
		args = build_args(cmd);
		if (handle_special_cmd(args, user_input) == 0)
			continue;
		if (access(args[0], X_OK) != 0)
			args[0] = build_cmd_path(args[0], _getenv("PATH"));
		else
			args[0] = strdup(args[0]);
		_exec(args);
		free(args[0]);
		free(args);
	}
	return (0);
}
