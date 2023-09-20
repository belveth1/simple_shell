#include "main.h"
/**
 * find_path -  Search In $PATH For Excutable Command
 * @cmd: Parsed Input
 * Return: 1  Failure  0  Success.
 */
char *find_path(char **cmd)
{
	char *path, *cp_path, *token, *file_path;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		cp_path = _strdup(path);
		token = strtok(path, ":");
		while (token != NULL)
		{
			file_path = malloc(_strlen(*cmd) + _strlen(token) + 2);
				if (file_path == NULL)
					file_path_handle(path, cp_path);
				_strcpy(file_path, token);
				_strcat(file_path, "/");
				_strcat(file_path, *cmd);
				if (stat(file_path, &buffer) == 0)
				{
					free_path(path, cp_path);
					return (file_path);
				}
				else
				{
				free(file_path);
				token = strtok(NULL, ":");
				}
		}
		free(cp_path);
			if (stat(*cmd, &buffer) == 0)
			{

				file_path = malloc(_strlen(*cmd) + 1);
				_strcpy(file_path, *cmd);
				free(path);
				return (file_path);
			}
			free(path);
	}
	return (NULL);
}
