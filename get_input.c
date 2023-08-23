#include "main.h"

/**
*_getline - func reads user input from stdin
*
* Return: returns the input
*/

char *_getline()
{
	int a, buff_size = 1024, rd;
	char c = 0;
	char *buffer = malloc(buff_size);

	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}

	for (a = 0; c != EOF && c != '\n'; a++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[a] = c;
		if (buffer[0] == '\n')
		{
			free(buffer);
			return ("\0");
		}
		if (a >= buff_size)
		{
			buffer = realloc(buffer, buff_size + 1);
			if (buffer == NULL)
			{
				return (NULL);
			}
		}
	}
	buffer[a] = '\0';
	hashtag_handle(buffer);
	return (buffer);
}

/**
 * hashtag_handle - func removes everything after #
 * @buffer: inpui
 *
 * Return: returns void
 */

void hashtag_handle(char *buffer)
{
	int a;

		for (a = 0; buffer[a] != '\0'; a++)
		{
			if (buffer[a] == '#')
			{
			buffer[a] = '\0';
			break;
			}
	}
}

