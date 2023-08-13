#include "shell.h"

/**
 * _strlen1 - Entry point
 * _strlen1: ..
 * @x: ...
 * Return: ..
 */
int _strlen1(char *x)
{
	int f = 0;

	if (!x)
		return (0);
	while (*x++)
		f++;
	return (f);
}

/**
 * _strcmp1 - Entry point
 * _strcmp1: ...
 * @x1: ..
 * @x2: ..
 * Return: ..
 */
int _strcmp1(char *x1, char *x2)
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
 * starts_with1 - Entry point
 * starts_with1: ...
 * @hay: ...
 * @need: ..
 * Return: ..
 */
char *starts_with1(const char *hay, const char *need)
{
	while (*need)
		if (*need++ != *hay++)
			return (NULL);
	return ((char *)hay);
}

/**
 * _strcat1 - Entry point
 * _strcat1: ..
 * @des: ..
 * @arc: ..
 * Return: ..
 */
char *_strcat1(char *des, char *arc)
{
	char *get = des;

	while (*des)
		des++;
	while (*arc)
		*des++ = *arc++;
	*des = *arc;
	return (get);
}
