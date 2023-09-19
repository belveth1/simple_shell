#include "main.h"
/**
 * read_file - handle file to read commands
 * @filen: name of file which contains commands
 * @argv: prgrame name
 * Return: -1 or  0
 */

void read_file(char *filen, char **argv)
{
	FILE *fp;
	char *input = NULL;
	size_t n = 0;
	int counter = 0;

	fp = fopen(filen, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&input, &n, fp)) != -1)
	{
		counter++;
		handle_file(input, counter, fp, argv);

	}
	if (input)
		free(input);
	free(fp);
	exit(0);
}
/**
 * handle_file - handle file and check it to excute it
 * @input: input command from file
 * @counter:Error Counter
 * @fp:File Descriptor
 * @argv:Program Name
 * Return : Excute A line void
 */
void handle_file(char *input, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int st = 0;

	cmd = cmd_line(input);

		if (_strncmp(cmd[0], "exit", 4) == 0)
		{
			exit_bul_file(cmd, input, fp);
		}
		else if (check_builtin(cmd) == 0)
		{
			st = excute_builtin(cmd, st);
			free(cmd);
		}
		else
		{
			st = execmd(argv, cmd, input, counter);
			free(cmd);
		}
}
/**
 * exit_bul_file - Exit Shell Case Of File
 * @input: Line From A File
 * @cmd: Parsed Command
 * @fd:File Descriptor
 * Return : Case Of Exit in A File Line
 */
void exit_bul_file(char **cmd, char *input, FILE *fd)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		fclose(fd);
		exit(errno);
	}

for (i = 0; cmd[1][i] != '\0'; i++)
{
if (_isalpha(cmd[1][i]) != 0)
{
perror("not number");
return;
}
}
statue = _atoi(cmd[1]);
free(input);
free(cmd);
fclose(fd);
exit(statue);
}
