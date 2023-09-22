#include "main.h"
/**
 * execmd - executes a command
 * @argv: Arrays of strings
 * @input: user input
 * @cmd: Command user entered(newline removed)
 * @counter: Variable to keep count the cmd
 * Return: 0 on success
 */
int execmd(char **argv, char **cmd, char *input, unsigned int counter)
{
	struct stat buffer;
	pid_t pid;
	char *path;
	(void)input;

	if (argv == NULL || cmd == NULL)
	{
		return (-1);
	}
	path = find_path(cmd);
	if (path == NULL)
	{
		print_error(argv, cmd, counter);
		free(cmd);
		return (0);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error forking");
		free_all(cmd, input);
		return (-1);
	}
	if (pid == 0)
	{
		if (stat(path, &buffer) == -1)
		{
			print_error(argv, cmd, counter);
			return (0);
		}
		else
			execve(path, cmd, environ);
	}
	else
	{
		wait(NULL);
	}
	free(path);
	return (1);
}
