#include "shell.h"

/**
 * _memset - Entry point
 * _memset: ..
 * @x: ..
 * @l: ..
 * @m: ..
 * Return: ..
 */
char *_memset(char *x, char l, unsigned int m)
{
	unsigned int u;

	for (u = 0; u < m; u++)
		x[u] = l;
	return (x);
}

/**
 * ffree - Entry point
 * ffree: ..
 * @xx: ..
 */
void ffree(char **xx)
{
	char **m = xx;

	if (!xx)
		return;
	while (*xx)
		free(*xx++);
	free(m);
}

/**
 * _realloc - Entry point
 * _realloc: .
 * @p: ...
 * @o: ..
 * @n: ..
 * Return: ..
 */
void *_realloc(void *p, unsigned int o, unsigned int n)
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
