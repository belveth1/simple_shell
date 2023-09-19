#include"main.h"
/**
 * check_builtin - investigate is there builtin fun
 *
 * @cmd:command to be checked
 * Return: 0 Succes -1 for Fail
 */
int check_builtin(char **cmd)
{
	built_in funs[] = {
		{"cd", NULL},
		{"env", NULL},
		{"echo", NULL},
		{NULL, NULL}
	};
	int i = 0;

		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((funs + i)->command)
	{
		if (_strcmp(cmd[0], (funs + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
