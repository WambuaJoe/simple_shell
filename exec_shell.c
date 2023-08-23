#include "main.h"

/**
 * main - execve example
 *
 * @argc: number of arguments
 * @argv: argument vectors
 *
 * Return: always returns 0.
 */

int main(int argc, char **argv)
{
	char *buff, **array, b;
	int count = 0;

	(void)argc;
	while (1)
	{
		count++;
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);

		buff = _getline();

		b = buff[0];

		if (b == '\0')
			continue;
		array = parser(buff);
		if (check_cmd(array[0]) == 0)
		{
			exec_builtin(array, count, argv[0]);
			free(array);
			free(buff);
			array = NULL;
			buff = NULL;
			continue;
		}
		else
			execute(array, count, argv, buff);
		free(array);
		free(buff);
	}
	return (0);
}

/**
*parser- func parses commmand input
*@buff: string containing command
*
*Return: returns parsed command
*/

char **parser(char *buff)
{
	char **cmd, *tok;
	int a;

	if (buff == NULL)
		return (NULL);

	tok = strtok(buff, " \n");
	if (tok == NULL)
		return (NULL);

	cmd = malloc(sizeof(char *) * 1024);

	a = 0;
	while (tok)
	{
		cmd[a++] = tok;
		tok = strtok(NULL, " \n");
	}
	cmd[a] = NULL;
	return (cmd);
}

/**
* execute - func executes cmds within shell
* @array: parsed commands
* @count: number of commands
* @argv: commandline args
* @buff: buffer containing input
*/

void execute(char **array, int count, char **argv, char *buff)
{
	int stat;

	if (fork() != 0)
	{
		wait(&stat);
	}
	else
	{
		if (_strncmp(array[0], "./", 2) != 0 && _strncmp(array[0], "/", 1) != 0)
			path_finder(&array[0]);

		if (execve(*array, array, environ) == -1)
		{
			printE(count, array[0], argv[0]);
			free(array);
			free(buff);
			exit(EXIT_FAILURE);
		}
	}
}

