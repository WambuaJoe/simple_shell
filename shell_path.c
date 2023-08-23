#include "main.h"

/**
 * path_finder -  search in $PATH or executable cmd
 * @cmd: parsed input
 *
 * Return: returns 1 on failure, else 0 upon success.
 */

void path_finder(char **cmd)
{
	char *path, *val, *cmd_path;
	struct stat buff;

	path = _getenv("PATH");
	val = strtok(path, ":");
	while (val != NULL)
	{
		cmd_path = build(*cmd, val);
		if (stat(cmd_path, &buff) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			break;
		}
		free(cmd_path);
		val = strtok(NULL, ":");
	}
	free(path);
}

/**
 * build - build command
 * @tok: executable command
 * @val: directory containing command
 *
 * Return: returns parsed full path of cmd or NULL case failed
 */

char *build(char *tok, char *val)
{
	char *cmd;
	size_t leng;

	leng = _strlen(val) + _strlen(tok) + 2;
	cmd = malloc(sizeof(char) * leng);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, leng);

	cmd = _strcat(cmd, val);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, tok);

	return (cmd);
}

/**
 * _getenv - func gets value of env var by name
 * @env_name: name of env variable
 *
 * Return: returns value of env variable, else NULL.
 */

char *_getenv(char *env_name)
{
	size_t nl, vl;
	char *val;
	int a, x, j;

	nl = _strlen(env_name);
	for (a = 0 ; environ[a]; a++)
	{
		if (_strncmp(env_name, environ[a], nl) == 0)
		{
			vl = _strlen(environ[a]) - nl;
			val = malloc(sizeof(char) * vl);
			if (!val)
			{
				free(val);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = nl + 1; environ[a][x]; x++, j++)
			{
				val[j] = environ[a][x];
			}
			val[j] = '\0';

			return (val);
		}
	}

	return (NULL);
}

