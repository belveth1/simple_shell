#include"main.h"

/**
 * exit_bultin - exit statue hsh shell
 * @cmd: array of pointers commands
 * @input: User input
 * @argv:argv[0] name of hsh shell
 * @c: excute Counter numbers
 * Return: Void with statue exit
 */
int exit_bultin(char **cmd, char *input, char **argv, int c)
{
	int statue;
	int i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	for (i = 0; cmd[1][i] != '\0'; i++)
	{
		if (_isalpha(cmd[1][i]) != 0)
		{
			exit_error(argv, cmd, c, cmd[1]);
			statue = 2;
			write(2, &statue, 1);
			return (2);
		}
	}
	if (cmd[1][0] == '-')
	{
		exit_error(argv, cmd, c, cmd[1]);
		statue = 2;
		write(2, &statue, 1);
		return (2);
	}
	statue = _atoi(cmd[1]);

	free(input);
	free(cmd);
	exit(statue);
}
/**
 * change_dir - change current directory to another by user
 * @cmd: input command
 * @er: Statue Last Command excuted
 * Return: 0 Succes 1 Failed (For Old Pwd Always 0 Case No Old PWD)
 */
int change_dir(char **cmd, int er)
{
	char cwd[PATH_MAX];
	 int value = -1;
	 (void)er;

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 * write_env - write Enviroment Variables on screen
 * @cmd: Command line by user
 * @er:Statue of Last command Excuted
 * Return:Always 0
 */
int write_env(char **cmd, int er)
{
	size_t i;
	int n;
	(void)cmd;
	(void)er;

	for (i = 0; environ[i] != NULL; i++)
	{
		n = _strlen(environ[i]);
		write(1, environ[i], n);
		write(1, "\n", 1);
	}
	return (0);
}
/**
 * echo_handle_builtin - add options to echo hsh
 * @st:statue of latest command excuted
 * @cmd: parsed command
 * Return: Always 0 Or Excute Normal Echo
 */
int echo_handle_builtin(char **cmd, int st)
{
char *path;
size_t pid = getppid();

if (_strncmp(cmd[1], "$?", 2) == 0)
{
print_number_in(st);
write(1, "\n", 1);
}
else if (_strncmp(cmd[1], "$$", 2) == 0)
{
print_number(pid);
write(1, "\n", 1);
}
else if (_strncmp(cmd[1], "$PATH", 5) == 0)
{
	path = _getenv("PATH");
	write(1, path, _strlen(path));
	write(1, "\n", 1);
	free(path);
}
else
return (echo_system(cmd));
return (0);
}

/**
 * exit_error - Prints an error to STDERR
 * @argv: Array of Strings
 * @counter: Keeps count of command run
 * @cmd: Command user entered
 * @alpha: turn from char to int
 */
void exit_error(char **argv, char **cmd, unsigned int counter, char *alpha)
{
	char *num_cmd = _itoa(counter);

	write(2, argv[0], _strlen(argv[0]));
	write(2, ": ", 2);
	write(2, num_cmd, _strlen(num_cmd));
	write(2, ": ", 2);
	write(2, cmd[0], _strlen(cmd[0]));
	write(2, ": Illegal number: ", 18);
	write(2, alpha, _strlen(alpha));
	write(2, "\n", 1);
	free(num_cmd);
}
