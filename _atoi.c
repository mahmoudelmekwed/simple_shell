#include "shell.h"

/**
 * interactive1 - Entry point
 * interactive1: ..
 * @info: ..
 * Return: ..
 */
int interactive1(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim1 - Entry point
 * is_delim1: ..
 * @x: ..
 * @delim1: ...
 * Return: ...
 */
int is_delim1(char x, char *delim1)
{
	while (*delim1)
		if (*delim1++ == x)
			return (1);
	return (0);
}

/**
 * _isalpha1 - Entry point
 * _isalpha1: ...
 * @u: ..
 * Return: ..
 */
int _isalpha1(int u)
{
	if ((u >= 'a' && u <= 'z') || (u >= 'A' && u <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi1 - Entry point
 * _atoi1: ..
 * @x: ..
 * Return: ..
 */
int _atoi(char *x)
{
	int l, s = 1, f = 0, out;
	unsigned int res = 0;

	for (l = 0; x[l] != '\0' && f != 2; l++)
	{
		if (x[l] == '-')
			s *= -1;
		if (x[l] >= '0' && x[l] <= '9')
		{
			f = 1;
			res *= 10;
			res += (x[l] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (s == -1)
		out = -res;
	else
		out = res;
	return (out);
}
