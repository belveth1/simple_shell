#include "main.h"
/**
 * main - main function for hsh shell
 * @argc: arguments count from user
 * @argv: shell name hsh
 * Return: exit with status value
 */
int main(int argc, char **argv)
{
	char *input;
	char **cmd;
	int st = 0;
	int count = 0, statue = 1;
	(void)argc;

	if (argv[1] != NULL)

	read_file(argv[1], argv);
	while (statue)
	{
		count++;
		input = NULL;
		if (isatty(STDIN_FILENO))
			prompt();
		 signal(SIGINT, handle_ctrlc);
		 input = _getline();
		 input_data(input);
		 cmd = cmd_line(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_bultin(cmd, input, argv, count);
		}
		else if (check_builtin(cmd) == 0)
		{
			st = excute_builtin(cmd, st);
			continue;
		}

		else
		{
			if (execmd(argv, cmd, input, count) == 0)
			continue;
		}
		free_all(cmd, input);
	}
	return (statue);
}
