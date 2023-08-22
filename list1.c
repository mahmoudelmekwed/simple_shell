#include "shell.h"

/**
 * list_len - get length of linked list
 * @hptr: first node pointer
 * Return: size
 */
size_t list_len(const list_t *hptr)
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
 * list_to_strings - ..
 * @hptr: first node pointer
 *
 * Return: ..
 */
char **list_to_strings(list_t *hptr)
{
	list_t *n = hptr;
	size_t i = list_len(hptr), j;
	char **strs;
	char *str;

	if (!hptr || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; n; n = n->next, i++)
	{
		str = malloc(_strlen(n->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, n->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - print elements of list_t linked list
 * @hptr: first node pointer
 * Return: size
 */
size_t print_list(const list_t *hptr)
{
	size_t i = 0;

	while (hptr)
	{
		_puts(convert_number(hptr->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(hptr->str ? hptr->str : "(nil)");
		_puts("\n");
		hptr = hptr->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - ..
 * @hptr: first node pointer
 * @pref: ..
 * @nex: the next prefix to match
 * Return: match node else null
 */
list_t *node_starts_with(list_t *hptr, char *pref, char nex)
{
	char *p = NULL;

	while (hptr)
	{
		p = starts_with(hptr->str, pref);
		if (p && ((nex == -1) || (*p == nex)))
			return (hptr);
		hptr = hptr->next;
	}
	return (NULL);
}

/**
 * get_node_index - return node index
 * @hptr: first node pointer
 * @n: node pointer
 * Return: node index else -1
 */
ssize_t get_node_index(list_t *hptr, list_t *n)
{
	size_t i = 0;

	while (hptr)
	{
		if (hptr == n)
			return (i);
		hptr = hptr->next;
		i++;
	}
	return (-1);
}
