#include"main.h"
/**
* _getline - Read data By User From keyboard(0)
* Return: pointer to char
*/
char *_getline()
{
int i, buffsize = BUFSIZE, rbyte;
char buffer = 0;
char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; buffer != EOF && buffer != '\n'; i++)
	{
		fflush(stdin);
		rbyte = read(STDIN_FILENO, &buffer, 1);
		if (rbyte == 0)
		{
			free(buff);
			write(1, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		buff[i] = buffer;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (i >= buffsize)
		{
			buff = my_realloc(buff, buffsize, buffsize + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[i] = '\0';
	hashtag_handle(buff);
	return (buff);
}
