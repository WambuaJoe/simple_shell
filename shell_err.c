#include "main.h"

/**
*printE - func prints error message
*@count: no of commands
*@cmd: command input
*@argv: commanline argument
*/

void printE(int count, char *cmd, char *argv)
{
	char *ptr;

	write(2, argv, _strlen(argv));
	write(2, ": ", 2);
	ptr = _itoa(count);
	write(2, ptr, _strlen(ptr));
	write(2, ": ", 2);
	write(2, cmd, _strlen(cmd));
	write(2, ": not found\n", 12);
}

