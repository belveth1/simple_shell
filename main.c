#include "main.h"
/**
 * main - main function for hsh shell
 * @argc: arguments count from user
 * @argv: shell name hsh
 * Return: exit with status value
 */
int main(int argc, char **argv)
{
	char *input = NULL;
	ssize_t n_read;
	size_t n = 0;
	char **cmd;
	int st = 0;
	int count = 0, statue = 1;
	(void)argc;

if (argv[1] != NULL)
read_file(argv[1], argv);
while (statue)
{
count++;
if (isatty(STDIN_FILENO))
prompt();
signal(SIGINT, handle_ctrlc);
n_read = getline(&input, &n, stdin);

if (n_read == -1 || n_read == EOF)
return (handle_ctrld(input));
cmd = cmd_line(input);

if (_strcmp(cmd[0], "exit") == 0)
{
st = exit_bultin(cmd, input, argv, count);
if (isatty(STDIN_FILENO) == 0 && st == 2)
exit(2);
}
else if (check_builtin(cmd) == 0)
{
st = excute_builtin(cmd, st);
free(cmd);
continue;
}
else
{

if (execmd(argv, cmd, input, count) == 0)
continue;
}
free(cmd);
}
return (st);
}
