
<p align="center">
	<img src="https://apply.holbertonschool.com/holberton-logo.png">
	<br>
	<img src="https://readme-typing-svg.herokuapp.com?font=Open+Sans&weight=900&pause=1000&color=1D5ABD&center=true&vCenter=true&width=500&lines=LOW+LEVEL+PROGRAMMING+PROJECT+IN+C" alt="Typing SVG" />
</p>

#
# <p align="center">C - Simple Shell</p>

## :bookmark: Table of contents
<details>
        <summary>
		CLICK TO ENLARGE :innocent:
        </summary>
        :memo: <a href="#objective">Objective</a>
        <br>
	    :page_facing_up: <a href="#description">Description</a>
        <br>
        :hammer: <a href="#tech-stack">Tech stack</a>
        <br>
        :floppy_disk: <a href="#prototype">Prototypes</a>
        <br>
        :clipboard: <a href="#requirements">Requirements</a>
        <br>
        :floppy_disk: <a href="#compilation-command">Compilation command</a>
        <br>
        :mortar_board: <a href="#instructions">Instructions</a>
        <br>
        :bookmark_tabs: <a href="#flowcharts">Flowcharts</a>
        <br>
        :open_file_folder: <a href="#files-description">Files description</a>
        <br>
        :computer: <a href="#install_run_use">How to install and run our Simple Shell</a>
        <br>
        :blue_book: <a href="#man-page">MAN page</a>
        <br>
        :heartpulse: <a href="#thanks">Thanks</a>
        <br>
        :construction_worker: <a href="#authors">Authors</a>
</details>

## :memo: <span id="objective">Objective</span>
To write a simple UNIX command interpreter.

## :page_facing_up: <span id="description">Description</span>

The Simple Shell  is a basic interactive shell that allows users to execute commands and perform various operations.
It provides a command prompt where users can enter commands for execution.
<br><br>
The shell supports standard commands, as well as some special commands for environment information and file operations.

## :hammer: <span id="tech-stack">Tech stack</span>

<div style="display: flex;">
	<img width="50px" height="50px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/a/ab/Logo-ubuntu_cof-orange-hex.svg/1200px-Logo-ubuntu_cof-orange-hex.svg.png">
	 &emsp;
	<img wigth="50px" height="50px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/9f/Vimlogo.svg/544px-Vimlogo.svg.png">
    &emsp;
    <img width="45px" height="50px"
src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/9a/Visual_Studio_Code_1.35_icon.svg/2048px-Visual_Studio_Code_1.35_icon.svg.png">
	 &emsp;
	<img width="45px" height="50px" src="https://upload.wikimedia.org/wikipedia/commons/1/19/C_Logo.png">
</div>

## :floppy_disk: <span id="prototype">Prototypes</span>

- `int main(void);` : main function of the Simple Shell (entry point).

- `char **build_args(char *cmd);` : initialize an array of strings containing command arguments.
- `char *build_cmd_path(char *cmd, char *path);` : builds path of the executable from given command string.

- `char *_getenv(const char *variable_name);` : get the value of an environment variable.
- `char *get_username(void);` : retrieve the username associated with the environment.
- `void print_env(char **environ);` : print the environment variables.

- `int _exec(char **args);` : executes a command according to arguments and environment, and handles errors.

- `char *get_current_directory(void);` : retrieve the current directory.
- `void print_file(const char *filename);` : print content of a file.
- `int handle_special_cmd(char **args, char *user_input);` : handles special commands like `env`, `exit`...

## :clipboard: <span id="requirements">Requirements</span>
- Allowed editors: **vim**, **emacs** or Visual Code Studio.
- All the files will be compiled on **Ubuntu 20.04 LTS** using **gcc**.
- The code should use the **betty style**.
- Global variables are not allowed.
- No more than 5 functions per file.
- The header files should be include guarded.
- Your shell should not have any memory leaks.

## :white_check_mark: List of allowed functions and system calls

- `all` functions from string.h
- `access` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `closedir` (man 3 closedir)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `_exit` (man 2 _exit)
- `fflush` (man 3 fflush)
- `fork` (man 2 fork)
- `free` (man 3 free)
- `getcwd` (man 3 getcwd)
- `getline` (man 3 getline)
- `getpid` (man 2 getpid)
- `isatty` (man 3 isatty)
- `kill` (man 2 kill)
- `malloc` (man 3 malloc)
- `open` (man 2 open)
- `opendir` (man 3 opendir)
- `perror` (man 3 perror)
- `printf` (man 3 printf)
- `fprintf` (man 3 fprintf)
- `vfprintf` (man 3 vfprintf)
- `sprintf` (man 3 sprintf)
- `putchar` (man 3 putchar)
- `read` (man 2 read)
- `readdir` (man 3 readdir)
- `signal` (man 2 signal)
- `stat` (__xstat) (man 2 stat)
- `lstat` (__lxstat) (man 2 lstat)
- `fstat` (__fxstat) (man 2 fstat)
- `strtok` (man 3 strtok)
- `wait` (man 2 wait)
- `waitpid` (man 2 waitpid)
- `wait3` (man 2 wait3)
- `wait4` (man 2 wait4)
- `write` (man 2 write)

## :floppy_disk: <span id="compilation-command">Compilation command</a>
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## :mortar_board: <span id="instructions">Instructions</span>

### <span id="mandatory-tasks">Mandatory tasks</span>

<details>
	<summary>
		<b>Task 0. README, man, AUTHORS</b>
	</summary>
    <ul>
        <li>Write a README.</li>
        <li>Write a man for your shell.</li>
        <li>You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository.</li>
    <ul>
</details>

<details>
	<summary>
		<b>Task 1. Betty would be proud</b>
	</summary>
	<ul>
        <li>Write a beautiful code that passes the Betty checks.</li>
    </ul>
</details>

<details>
	<summary>
		<b>Task 2. Simple shell 0.1</b>
	</summary>
	<ul>
        <li>Write a UNIX command line interpreter.</li>
        <ul>
            <li>Usage: simple_shell</li>
            <li>Your Shell should:</li>
            <ul>
                <li>Display a prompt and wait for the user to type a command. A command line always ends with a new line.</li>
                <li>The prompt is displayed again each time a command has been executed.</li>
                <li>The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.</li>
                <li>The command lines are made only of one word. No arguments will be passed to programs.</li>
                <li>If an executable cannot be found, print an error message and display the prompt again.</li>
                <li>Handle errors.</li>
                <li>You have to handle the “end of file” condition (Ctrl+D).</li>
            </ul>
            <li>You don’t have to:</li>
            <ul>
                <li>Use the PATH.</li>
                <li>Implement built-ins.</li>
                <li>Handle special characters : ", ', \, *, &, #.</li>
                <li>Be able to move the cursor.</li>
                <li>Handle commands with arguments.</li>
            </ul>
        </ul>
    </ul>
    execve will be the core part of your Shell, don’t forget to pass the environ to it…
<br>
<br>

```
julien@ubuntu:~/shell$ ./shell
#cisfun$ ls
./shell: No such file or directory
#cisfun$ /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
#cisfun$ ^[[D^[[D^[[D
./shell: No such file or directory
#cisfun$ ^[[C^[[C^[[C^[[C
./shell: No such file or directory
#cisfun$ exit
./shell: No such file or directory
#cisfun$ ^C
julien@ubuntu:~/shell$ echo "/bin/ls" | ./shell
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
#cisfun$ julien@ubuntu:~/shell$
```
</details>

<details>
	<summary>
		<b>Task 3. Simple shell 0.2</b>
	</summary>
	<ul>
        <li>Simple shell 0.1 +</li>
        <ul>
            <li>Handle command lines with arguments</li>
        </ul>
    </ul>
</details>

<details>
	<summary>
		<b>Task 4. Simple shell 0.3</b>
	</summary>
	<ul>
        <li>Simple shell 0.2 +</li>
        <ul>
            <li>Handle the PATH.</li>
            <li>fork must not be called if the command doesn’t exist.</li>
        </ul>
    </ul>
<br>

```
julien@ubuntu:~/shell$ ./shell_0.3
:) /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
:) ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
:) ls -l /tmp
total 20
-rw------- 1 julien julien    0 Dec  5 12:09 config-err-aAMZrR
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-colord.service-V7DUzr
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-rtkit-daemon.service-ANGvoV
drwx------ 3 root   root   4096 Dec  5 12:07 systemd-private-062a0eca7f2a44349733e78cb4abdff4-systemd-timesyncd.service-CdXUtH
-rw-rw-r-- 1 julien julien    0 Dec  5 12:09 unity_support_test.0
:) ^C
julien@ubuntu:~/shell$
```
</details>

<details>
	<summary>
		<b>Task 5. Simple shell 0.4</b>
	</summary>
	<ul>
        <li>Simple shell 0.3 +</li>
        <ul>
            <li>Implement the exit built-in, that exits the shell.</li>
            <li>Usage: exit.</li>
            <li>You don’t have to handle any argument to the built-in exit.</li>
        </ul>
    </ul>
</details>

<details>
	<summary>
		<b>Task 6. Simple shell 1.0</b>
	</summary>
	<ul>
        <li>Simple shell 0.4 +</li>
        <ul>
            <li>Implement the env built-in, that prints the current environment.</li>
        </ul>
    </ul>
<br>

```
julien@ubuntu:~/shell$ ./simple_shell
$ env
USER=julien
LANGUAGE=en_US
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/julien
C_IS=Fun_:)
DESKTOP_SESSION=ubuntu
LOGNAME=julien
TERM=xterm-256color
PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DISPLAY=:0
$ exit
julien@ubuntu:~/shell$
```
</details>


### <span id="advanced-tasks">Advanced tasks</a>

<details>
	<summary>
		<b>Task 12. Simple shell 0.4.2</b>
	</summary>
	<ul>
        <li>Simple shell 0.4 +</li>
        <li>Handle Ctrl+C: your shell should not quit when the user inputs ^C</li>
man 2 signal.
    </ul>
<br>

```
julien@ubuntu:~/shell$ ./shell_0.4.2
$ ^C
$ ^C
$ ^C
$ ls /var
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  snap  spool  tmp
$ ^C
$ ^C
$ ^C
$ exit
julien@ubuntu:~/shell$ 
```
</details>

<details>
	<summary>
		<b>Task 14. cd</b>
	</summary>
	<ul>
        <li>Simple shell 1.0 +</li>
        <li>Implement the builtin command cd:</li>
        <ul>
            <li>Changes the current directory of the process.</li>
            <li>Command syntax: cd [DIRECTORY].</li>
            <li>If no argument is given to cd the command must be interpreted like cd $HOME.</li>
            <li>You have to handle the command cd -.</li>
            <li>You have to update the environment variable PWD when you change directory.</li>
        </ul>
man chdir, man getcwd
    </ul>
</details>

## :bookmark_tabs: <span id="flowcharts">Flowcharts</a>

![Image](https://raw.githubusercontent.com/Pandolowitz/holbertonschool-simple_shell/master/resources/simple_shell_flowshart.png)

## :open_file_folder: <span id="files-description">Files description</span>

|         FILE         |                                    DESCRIPTION                                    |
| :------------------: | :-------------------------------------------------------------------------------: |
|       resources      |                           contain images for README.md                            |
|        AUTHORS       |             list of all contributors to the content of the repository             |
|       README.md      |                              this readme file :wink:                              |
|        args.c        |                 contains the argument and path management functions               |
|      commands.c      |          contains functions to handles special commands like env, exit...         |
|        env.c         |                     contains environment management functions                     |
|        exec.c        |               contains function to executes a command with arguments              |
|        main.c        |               contains the mains function of the shell (entry point)              |
|        main.h        |                    includes libraries and function prototypes                     |
|  man_1_simple_shell  |                            man page of the Simple Shell                           |

## :computer: <span id="install">How to install run and use our Simple Shell</a>

### Install and run:

To install and run Simple Shell, follow these steps:

Clone the repository using the following command:
```
git clone https://github.com/Pandolowitz/holbertonschool-simple_shell.git
```

Navigate to the directory where the repository was cloned.

Compile the program by running the following command:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Run the program by typing the following command:
```
./hsh
```

### Using the Simple Shell:

To use Simple Shell, type a command and press Enter.
<br>
The program will execute the command and display the output on the screen.

Here are some examples of commands that you can run:

- `ls`: list the contents of the current directory.
- `pwd`: print the path of the current working directory.
- `echo`: display a message on the screen.
- `mkdir`: create a new directory.
- `exit`: exit the shell.

You can also run commands that require arguments, such as:

- `ls -l`: list the contents of the current directory in long format.
- `mkdir 42`: create a new directory called "42".
- `echo "Hello, Hugo!"`: display the message "Hello, Hugo!" on the screen.

## :blue_book: <span id="man-page">MAN page</a>

Execution: `man_1_simple_shell`

![Image](https://raw.githubusercontent.com/Pandolowitz/holbertonschool-simple_shell/master/resources/man_page.png)

## :hearts: <span id="thanks">Thanks</span>

A big thank you to all our Holberton School peers for their help and support throughout this project.
<br>

## :construction_worker: <span id="authors">Authors</span>
**Fabien CHAVONET**
- Github: [@Pandolowitz](https://github.com/Pandolowitz)

**Pierre-Émmanuel SAINT-MÉZARD**
- Github: [@Eonvorax](https://github.com/Eonvorax)