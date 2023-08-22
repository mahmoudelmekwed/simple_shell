#include "shell.h"

/**
 * interactive - Entry point
 * interactive: ..
 * @i: ..
 * Return: ..
 */
int interactive(info_t *i)
{
	return (isatty(STDIN_FILENO) && i->readfd <= 2);
}

/**
 * is_delim - Entry point
 * is_delim: ..
 * @x: ..
 * @delim: ...
 * Return: ...
 */
int is_delim(char x, char *delim)
{
	while (*delim)
		if (*delim++ == x)
			return (1);
	return (0);
}

/**
 * _isalpha - Entry point
 * _isalpha: ...
 * @u: ..
 * Return: ..
 */
int _isalpha(int u)
{
	if ((u >= 'a' && u <= 'z') || (u >= 'A' && u <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Entry point
 * _atoi: ..
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
