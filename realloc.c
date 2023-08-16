#include "shell.h"

/**
 * _memset1 - Entry point
 * _memset1: ..
 * @x: ..
 * @l: ..
 * @m: ..
 * Return: ..
 */
char *_memset1(char *x, char l, unsigned int m)
{
	unsigned int u;

	for (u = 0; u < m; u++)
		x[u] = l;
	return (x);
}

/**
 * ffree1 - Entry point
 * ffree1: ..
 * @xx: ..
 */
void ffree1(char **xx)
{
	char **m = xx;

	if (!xx)
		return;
	while (*xx)
		free(*xx++);
	free(m);
}

/**
 * _realloc1 - Entry point
 * _realloc1: .
 * @p: ...
 * @o: ..
 * @n: ..
 * Return: ..
 */
void *_realloc1(void *p, unsigned int o, unsigned int n)
{
	char *x;

	if (!p)
		return (malloc(n));
	if (!n)
		return (free(p), NULL);
	if (n == o)
		return (p);
	x = malloc(n);
	if (!x)
		return (NULL);

	o = o < n ? o : n;
	while (o--)
		x[o] = ((char *)p)[o];
	free(p);
	return (x);
}
