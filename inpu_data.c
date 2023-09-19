#include"main.h"
/**
 * input_data - input datainto File By User Input
 * @data: User Input
 * Return: -1 Fail 0 Succes
 */
int input_data(char *data)
{
	char *filename = ".data";
	ssize_t fd, wbyte;
	int size = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (data)
	{
		while (data[size])
			size++;
		wbyte = write(fd, data, size);
		if (wbyte < 0)
			return (-1);
	}
	return (1);
}
