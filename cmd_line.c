#include"main.h"

/**
 * cmd_line - Parsing Line Of Input into array of pointers
 * @input:User Input To be Parsed
 * Return: Array Of pointers Chars
 */
char **cmd_line(char *input)
{
	char **cmd;
	char *token;
	int i;

	if (input == NULL)
		return (NULL);
	 cmd = malloc(sizeof(char *) * 1024);
	if (!cmd)
	{
		perror("hsh");
		return (NULL);
	}
	token = strtok(input, " \n");
	for (i = 0; token; i++)
	{
		cmd[i] = token;
		token = strtok(NULL, " \n");
	}
	cmd[i] = NULL;
	return (cmd);
}
