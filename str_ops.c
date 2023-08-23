#include "main.h"

/**
 * _strncmp - compares amount (n) Of chars Of two strings
 * @s1: string
 * @s2: strng
 * @n: amount of chars to compare
 *
 * Return: returns 1 if strings don't match, else 0
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t a;

	if (s1 == NULL)
		return (-1);
	for (a = 0; a < n && s2[a]; a++)
	{
		if (s1[a] != s2[a])
		{
			return (1);
		}
	}
	return (0);
}

/**
*_strdup - func thatduplicates a string
*@str: the str parameter
*
*Return: returns ptr to duplicate of str
*/

char *_strdup(char *str)
{
	char *c;
	size_t a = 0, leng = 0;

	leng = _strlen(str);

	c = malloc(sizeof(char) * (leng + 1));

	if (c == NULL)
	{
		free(c);
		return (NULL);
	}

	while (a <= len)
	{
		c[a] = str[a];
		a++;
	}
	return (c);
}

/**
*_isdigit - this  checks if it's a digit
*@cc: parameter int to test
*
*Return: returns 1 if it's )-9, else 0
*/

int _isdigit(char cc)
{
	if (cc >= '0' && cc <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
*_atoi - converts str to int
*@c: pointer to string
*
*Return: returns int from str
*/

int _atoi(char *c)
{
	unsigned int numb = 0, n, a;
	int sign = 1;

	for (n = 0; *(c + n) != '\0'; n++)
	{
	}

	for (a = 0; a < n; a++)
	{
		if (c[a] == '-')
			sign *= -1;

		else if (c[a] >= '0' && c[a] <= '9')
		numb = numb * 10 + (c[a] - 48);

		else if (numb > 0)
			break;
	}

	return (numb * sign);
}

