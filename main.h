#ifndef MAIN_H
#define MAIN_H

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

char **build_args(char *cmd);
char *build_cmd_path(char *cmd, char *path);

char *_getenv(const char *variable_name);
char *get_username(void);
void print_env(char **environ);

int _exec(char **args);

char *get_current_directory(void);
int handle_special_cmd(char **args, char *user_input, int status);
void print_file(const char *filename);

#endif
