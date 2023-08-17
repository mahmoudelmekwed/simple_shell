#include "shell.h"

/**
 * list_len1 - Entry point
 * list_len1: ..
 * @x: ..
 * Return: ..
 */
size_t list_len1(const list_t *x)
{
	size_t m = 0;

	while (x)
	{
		x = x->next;
		m++;
	}
	return (m);
}

/**
 * list_to_strings1 - Entry point
 * list_to_strings1: ..
 * @h: ..
 * Return: ..
 */
char **list_to_strings1(list_t *h)
{
	list_t *n = h;
	size_t l = list_len1(h), k;
	char **str2;
	char *str1;

	if (!h || !l)
		return (NULL);
	str2 = malloc(sizeof(char *) * (l + 1));
	if (!str2)
		return (NULL);
	for (l = 0; n; n = n->next, l++)
	{
		str1 = malloc(_strlen1(n->str) + 1);
		if (!str1)
		{
			for (k = 0; k < l; k++)
				free(str2[k]);
			free(str2);
			return (NULL);
		}
		str1 = _strcpy1(str1, n->str);
		str2[l] = str1;
	}
	str2[l] = NULL;
	return (str2);
}

/**
 * print_list1 - Entry point
 * print_list1: ..
 * @g: ..
 * Return: ..
 */
size_t print_list1(const list_t *g)
{
	size_t x = 0;

	while (g)
	{
		_puts1(convert_number1(g->num, 10, 0));
		_putchar1(':');
		_putchar1(' ');
		_puts1(g->str ? g->str : "(nil)");
		_puts1("\n");
		g = g->next;
		x++;
	}
	return (x);
}

/**
 * node_starts_with1 - Entry point
 * node_starts_with1: ..
 * @n: ..
 * @p: ..
 * @cr: ..
 * Return: ..
 */
list_t *node_starts_with1(list_t *n, char *p, char cr)
{
	char *ptr = NULL;

	while (n)
	{
		ptr = starts_with1(n->str, p);
		if (ptr && ((cr == -1) || (*ptr == cr)))
			return (n);
		n = n->next;
	}
	return (NULL);
}

/**
 * get_node_index1 - Entry point
 * get_node_index1: ..
 * @h: ..
 * @n: ..
 * Return: ..
 */
ssize_t get_node_index1(list_t *h, list_t *n)
{
	ssize_t x = 0;

	while (h)
	{
		if (h == n)
			return (x);
		h = h->next;
		x++;
	}
	return (-1);
}

