#include"main.h"
/**
 * echo_system - Excute Normal Echo
 * @cmd: Parsed Command
 * Return: 0 Succes -1 Fail
 */
int echo_system(char **cmd)
{
	pid_t pid;

	pid = fork();


	if (pid == -1)
	{
		perror("Error forking");
		return (-1);
	}

	if (pid == 0)
		execve("/bin/echo", cmd, environ);
	else
		wait(NULL);
	return (0);
}
