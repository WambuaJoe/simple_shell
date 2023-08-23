#include "main.h"

/**
 * *_strcpy - copy string pointed to by src including null byte(\0)
 *            to buff pointed to by dest
 * @src: source of str to be copied
 * @dest: destination of str to be copied
 *
 * Return: ptr to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i, o = 0;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[o] = src[i];
		o++;
	}
	dest[o] = '\0';

	return (dest);
}

/**
 * _strcat - this funct appends src str to the dest str
 *           overwriting the terminating null byte at end
 *           of dest, then adds terminating null byte
 * @src: 1st str
 * @dest: 2nd str
 *
 * Return: returns ptr to resulting str(dest)
 */

char *_strcat(char *dest, char *src)
{
	int leng_dest = 0;
	int leng_src = 0;

	for (; dest[leng_dest] != '\0'; len_dest++)
		;

	for (; src[leng_src] != '\0' ;)
		dest[leng_dest++] = src[leng_src++];

	dest[leng_dest] = '\0';
	return (dest);
}

/**
 * _strcmp - this func compares two strings
 *
 * @s1: 1st string
 * @s2: 2nd string
 * Return: 0 if identical
 *         < 0 if 1st char in s1's ASCII value less than that of s2
 *         > 0 if 1st char in s2's ASCII val greater than that of s2
 */

int _strcmp(char *s1, char *s2)
{
	int a = 0;

	while (s1[a] == s2[a])
	{
		if (s1[a] == '\0')
			return (0);
		a++;
	}

	return (s1[a] - s2[a]);
}

/**
 * _strlen - returns len of str
 * @s: str whose len is to be determined
 *
 * Return: Always returns 0
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; *s != '\0'; s++)
		i++;

	return (i);
}

/**
 * *_strncpy - this func copies a str
 * @dest: the  destination str
 * @src: source str
 * @n: num of bytes to be copied
 *
 * Return: returns ptr to dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int a = 0;

	while (src[a] != '\0' && a < n)
	{
		dest[a] = src[a];
		a++;
	}

	while (a < n)
	{
		dest[a] = '\0';
		a++;
	}

	return (dest);
}

