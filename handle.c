#include "main.h"
/**
 * handle_ctrlc - Ctrl+C handler
 * @signum: Signal number
 *
 */
void handle_ctrlc(int signum)
{
	(void) signum;

	write(1, "\n$ ", 3);
}
/**
 * hashtag_handle - delete  anything after #
 * @buff: input data by _getline;
 * Return:void
 */
void hashtag_handle(char *buff)
{
	int i;

		for (i = 0; buff[i] != '\0'; i++)
		{
			if (buff[i] == '#')
			{
			buff[i] = '\0';
			break;
			}
	}
}
