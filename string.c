#include "shell.h"

/**
 * _strlen - Entry point
 * _strlen: ..
 * @x: ...
 * Return: ..
 */
int _strlen(char *x)
{
	int f = 0;

	if (!x)
		return (0);
	while (*x++)
		f++;
	return (f);
}

/**
 * _strcmp - Entry point
 * _strcmp: ...
 * @x1: ..
 * @x2: ..
 * Return: ..
 */
int _strcmp(char *x1, char *x2)
{
	while (*x1 && *x2)
	{
		if (*x1 != *x2)
			return (*x1 - *x2);
		x1++;
		x2++;
	}
	if (*x1 == *x2)
		return (0);
	else
		return (*x1 < *x2 ? -1 : 1);
}

/**
 * starts_with - Entry point
 * starts_with: ...
 * @hay: ...
 * @need: ..
 * Return: ..
 */
char *starts_with(const char *hay, const char *need)
{
	while (*need)
		if (*need++ != *hay++)
			return (NULL);
	return ((char *)hay);
}

/**
 * _strcat - Entry point
 * _strcat: ..
 * @des: ..
 * @arc: ..
 * Return: ..
 */
char *_strcat(char *des, char *arc)
{
	char *get = des;

	while (*des)
		des++;
	while (*arc)
		*des++ = *arc++;
	*des = *arc;
	return (get);
}
