#include"main.h"
/**
 * excute_builtin - excute specific Builtin Command
 * @cmd: input Command
 * @er:statue of last Excute
 * * Return: -1 Fail 0 Succes
 */

int excute_builtin(char **cmd, int er)
{
	 built_in bil[] = {
		{"cd", change_dir},
		{"env", write_env},
		{"echo", echo_handle_builtin},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->bul(cmd, er));
		}
		i++;
	}
	return (-1);
}
