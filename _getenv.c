#include "main.h"
/**
 * _getenv - get any value of environmen variables by name
 * @name: environment variable name
 * Return: value of specific name of variable environment or NULL
 */
char *_getenv(char *name)
{
	size_t n_length, v_length;
	int i, x, y;
	char *value;

	y = 0;

	n_length = _strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], n_length) == 0)
		{
			v_length = _strlen(environ[i]) - n_length;
			value = malloc(sizeof(char) * (v_length + 1));
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}


			for (x = n_length + 1 ; environ[i][x]; x++, y++)
			{
				value[y] = environ[i][x];
			}
			value[y] = '\0';

			return (value);
		}
	}

	return (NULL);
}
