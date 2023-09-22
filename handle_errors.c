#include "main.h"
/**
 * print_error - Prints an error to STDERR
 * @argv: Array of Strings
 * @counter: Keeps count of command run
 * @cmd: Command user entered
 */
void print_error(char **argv, char **cmd, unsigned int counter)
{
	char *num_cmd = _itoa(counter);

	write(2, argv[0], _strlen(argv[0]));
	write(2, ": ", 2);
	write(2, num_cmd, _strlen(num_cmd));
	write(2, ": ", 2);
	write(2, cmd[0], _strlen(cmd[0]));
	write(2, ": not found\n", 12);

if (isatty(STDIN_FILENO) == 0)
	exit(2);
free(num_cmd);
}
