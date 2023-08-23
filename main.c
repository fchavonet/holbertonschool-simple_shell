#include "main.h"

/**
 * check_terminal - prints a prompt if standard input is from a terminal
 * @user: string value of USER variable in ENV, "root" if not defined
 * @pwd: string path of current directory
 *
 * Return: nothing
 */
void check_terminal(char *user, char *pwd)
{
	if (isatty(STDIN_FILENO))
	{
		printf("\033[32m@%s\033[0m:\033[36m%s\033[0m $ ", user, pwd);
		fflush(stdout);
	}
}
/**
 * check_eof - checks input for EOF, frees memory and closes the shell on EOF
 * @user_input: user input to free if EOF was received
 * @getline_result: return value from getline, equal to EOF (-1) on EOF
 * @status: exit value from the last command executed
 *
 * Return: nothing
 */
void check_eof(char *user_input, ssize_t getline_result, int status)
{
	if (getline_result == EOF)
	{
		free(user_input);
		if (isatty(STDIN_FILENO))
			printf("\n");
		exit(status);
	}
}

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
	int status = 0;

	while (1)
	{
		check_terminal(username, current_dir);
		getline_result = getline(&user_input, &max_cmd_length, stdin);
		check_eof(user_input, getline_result, status);
		cmd = user_input;
		while (*cmd == ' ' || *cmd == '\t')
			cmd++;
		if (strcmp(cmd, "\n") == 0)
			continue;
		cmd[strlen(cmd) - 1] = '\0';
		args = build_args(cmd);
		if (handle_special_cmd(args, user_input, status) == 0)
			continue;
		if (access(args[0], X_OK) != 0)
			args[0] = build_cmd_path(args[0], _getenv("PATH="));
		else
			args[0] = strdup(args[0]);

		if (access(args[0], X_OK) != 0)
		{
			fprintf(stderr, "./hsh: %s: command not found\n", strtok(cmd, " "));
			status = 127;
		}
		else
		{
			status = _exec(args, cmd);
		}
		free(args[0]);
		free(args);
	}
	return (0);
}
