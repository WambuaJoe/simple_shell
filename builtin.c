#include "main.h"

/**
 * check_cmd - func checks if cmd is builtin cmd
 *
 * @cmd: cmd to check
 *
 * Return: returns 0 if true, else -1
 */

int check_cmd(char *cmd)
{
	int a = 0;
	char *arr_cmd[] = {"exit", "env", "clear", NULL};

	while (arr_cmd[a])
	{
		if (_strcmp(arr_cmd[a], cmd) == 0)
			return (0);

		a++;
	}
	return (-1);
}

/**
 * exec_builtin - func execs builtin commands
 * @cmd: cmd to execute
 * @counter: cmd no
 * @argv: arg vector
 *
 * Return: returns 0 on success, -1 otherwise
 */

int exec_builtin(char **cmd, int counter, char *argv)
{
	int a = 0;
	built_ins selector[] = {
		{"exit", __exit},
		{"env", _env},
		{"clear", clear},
		{NULL, NULL}
	};

	while ((selector + a)->cmd)
	{
		if (_strcmp((selector + a)->cmd, cmd[0]) == 0)
			return ((selector + a)->func(cmd, counter, argv));
		a++;
	}
	return (-1);
}

