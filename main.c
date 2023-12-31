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
 * check_ctrlc - Handles the SIGINT (Ctrl+C) signal.
 * @signo: the signal number (not used in this function).
 */
void check_ctrlc(int signo)
{
	(void)signo;
	printf("\n");
	check_terminal(get_username(), get_current_directory());
	fflush(stdout);
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
		signal(SIGINT, check_ctrlc);
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
		if (handle_special_cmd(args, user_input, status, &current_dir) == 0)
			continue;
		if (strchr(args[0], '/') != NULL)
			args[0] = strdup(args[0]);
		else
			args[0] = build_cmd_path(args[0], _getenv("PATH="));
		if (args[0] == NULL)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", strtok(cmd, " "));
			status = 127;
		}
		else
		{
			status = _exec(args, cmd);
			free(args[0]);
		}
		free(args);
	}
	return (0);
}
