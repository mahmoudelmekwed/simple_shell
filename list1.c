#include "shell.h"

/**
<<<<<<< HEAD
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
=======
 * list_len1 - get length of linked list
 * @hptr: first node pointer
 * Return: size
 */
size_t list_len1(const list_t *hptr)
{
	size_t i = 0;

	while (hptr)
	{
		hptr = hptr->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings1 - ..
 * @hptr: first node pointer
 *
 * Return: ..
 */
char **list_to_strings1(list_t *hptr)
{
	list_t *n = hptr;
	size_t i = list_len1(hptr), j;
	char **strs;
	char *str;

	if (!hptr || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; n; n = n->next, i++)
	{
		str = malloc(_strlen1(n->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy1(str, n->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list1 - print elements of list_t linked list
 * @hptr: first node pointer
 * Return: size
 */
size_t print_list1(const list_t *hptr)
{
	size_t i = 0;

	while (hptr)
	{
		_puts1(convert_number1(hptr->num, 10, 0));
		_putchar1(':');
		_putchar1(' ');
		_puts1(hptr->str ? hptr->str : "(nil)");
		_puts1("\n");
		hptr = hptr->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with1 - ..
 * @hptr: first node pointer
 * @pref: ..
 * @nex: the next prefix to match
 * Return: match node else null
 */
list_t *node_starts_with1(list_t *hptr, char *pref, char nex)
{
	char *p = NULL;

	while (hptr)
	{
		p = starts_with1(hptr->str, pref);
		if (p && ((nex == -1) || (*p == nex)))
			return (hptr);
		hptr = hptr->next;
>>>>>>> 5d5a3b5e83f8d74e37914cc089c16338c570a142
	}
	return (NULL);
}

/**
<<<<<<< HEAD
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
=======
 * get_node_index1 - return node index
 * @hptr: first node pointer
 * @n: node pointer
 * Return: node index else -1
 */
size_t get_node_index1(list_t *hptr, list_t *n)
{
	size_t i = 0;

	while (hptr)
	{
		if (hptr == n)
			return (i);
		hptr = hptr->next;
		i++;
>>>>>>> 5d5a3b5e83f8d74e37914cc089c16338c570a142
	}
	return (-1);
}
