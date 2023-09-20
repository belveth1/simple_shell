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
