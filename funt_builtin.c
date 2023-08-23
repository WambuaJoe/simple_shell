#include "main.h"

/**
 * __exit - func exits shell
 * @cmd: the command
 * @counter: no cmd executed
 * @argv: arg vector
 *
 * Return: returns 0 on success, -1 otherwise
 */

int __exit(char **cmd, int counter, char *argv)
{
	int a = 0, stat = 0;
	char *ptr;

	if (!cmd[1])
	{
		free(cmd);
		exit(0);
		return (0);
	}

	while (cmd[1][a])
	{
		if (_isdigit(cmd[1][i]) == 0)
		{
			write(2, argv, _strlen(argv));
			write(2, ": ", 2);
			ptr = _itoa(counter);
			write(2, ptr, _strlen(ptr));
			write(2, ": ", 2);
			write(2, cmd[0], _strlen(cmd[0]));
			write(2, ": Illegal number: ", 18);
			write(2, cmd[1], _strlen(cmd[1]));
			write(2, "\n", 1);
			return (-1);
		}
	a++;
	}
	stat = _atoi(cmd[1]);
	free(cmd);
	exit(stat);
	return (0);
}

/**
 * _env - funct prints the current env
 * @cmd: the command
 * @counter: cmd number
 * @argv: arg vector
 * Return: returns 0 on success, -1 otherwise
 */

int _env(char **cmd, int counter, char *argv)
{
	int a = 0;
	(void)cmd;
	(void)counter;
	(void)argv;

	while (environ[a])
	{
		write(1, environ[a], _strlen(environ[a]));
		write(1, "\n", 1);
		a++;
	}
	return (0);
}


/**
 * clear - funct clears terminal window
 * @cmd: acommand
 * @count: cmd number
 * @argv: arg vector
 *
 * Return: returns 0 on success, -1 otherwise
 */

int clear(char **cmd, int count, char *argv)
{
	(void)cmd;
	(void)count;
	(void)argv;

	write(1, "\033[1;1H\033[2J", 10);

	return (0);
}

