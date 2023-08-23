#include "main.h"

/**
 * *_memcpy - this func copies mem area
 * @dest: destination str
 * @src: source str
 * @n: no of bytes
 *
 * Return: returns ptr to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
	{
		dest[a] = src[a];
	}
	return (dest);
}

/**
 * *_memset - fill mem with constant byte
 * @s: pointer to str s
 * @b: constant byte
 * @n: no of bytes of mem
 *
 * Return: returns ptr to s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
	{
		s[a] = b;
	}
	return (s);
}

/**
 * _itoa - this func converts int to char
 * @n: the int to convert
 *
 * Return: returns the char pointer
 */

char *_itoa(unsigned int n)
{
	int leng = 0, a = 0, numb;
	char *c;
	char temp;

	numb = n;
	while (numb != 0)
	{
		leng++;
		numb /= 10;
	}
	c = malloc(leng + 1);
	if (!c)
		return (NULL);
	*c = '\0';
	while (n / 10)
	{
		c[a] = (n % 10) + '0';
		n /= 10;
		a++;
	}
	c[a] = (n % 10) + '0';

	for (a = 0; a < (leng / 2); a++)
	{
		temp = c[a];
		c[a] = c[(leng - 1) - a];
		c[(leng - 1) - a] = temp;
	}
	c[a + 1] = '\0';
	return (c);
}

