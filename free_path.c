#include "main.h"
/**
 * free_path - free path and copy of path
 * @path: Path
 * @cp_path: Copy of path
 */
void free_path(char *path, char *cp_path)
{
	free(path);
	free(cp_path);
}
/**
 * file_path_handle - free path and copy of path in case some errors
 * @path: Path
 * @cp_path: Copy of path
 */
void file_path_handle(char *path, char *cp_path)
{
	free_path(path, cp_path);
	exit(EXIT_FAILURE);
}
/**
 * free_all - fuc to delete and free space
 * @cmd : the command line
 * @line : the line
 */
void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
	line = NULL;
	cmd = NULL;
}
