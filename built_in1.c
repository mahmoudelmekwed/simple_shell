#include "shell.h"

/**
 * _myhistory - displays the history list.
 * @i: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 0
 */
int _myhistory(info_t *i)
{
	print_list1(i->history);
	return (0);
}

/**
 * unset_alias - Sets alias
 * @i: parameter struct
 * @st: the string alias
 *
 * Return: 0 success, 1 error
 */
int unset_alias(info_t *i, char *st)
{
	char *x, v;
	int res;

	x = _strchr1(st, '=');
	if (!x)
		return (1);
	v = *x;
	*x = 0;
	res = delete_node_at_index1(&(i->alias),
		get_node_index1(i->alias, node_starts_with1(i->alias, st, -1)));
	*x = v;
	return (res);
}

/**
 * set_alias - sets alias to string
 * @i: parameter struct
 * @st: ..
 *
 * Return: 0 success, 1 error
 */
int set_alias(info_t *i, char *st)
{
	char *x;

	x = _strchr1(st, '=');
	if (!x)
		return (1);
	if (!*++x)
		return (unset_alias(i, st));

	unset_alias(i, st);
	return (add_node_end1(&(i->alias), st, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @n: node
 *
 * Return: 0 success, 1 error
 */
int print_alias(list_t *n)
{
	char *x = NULL, *i = NULL;

	if (n)
	{
		x = _strchr1(n->str, '=');
		for (i = n->str; i <= x; i++)
		_putchar1(*i);
		_putchar1('\'');
		_puts1(x + 1);
		_puts1("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - ..
 * @i: ..
 *
 *  Return: 0
 */
int _myalias(info_t *i)
{
	int a = 0;
	char *x = NULL;
	list_t *n = NULL;

	if (i->argc == 1)
	{
		n = i->alias;
		while (n)
		{
			print_alias(n);
			n = n->next;
		}
		return (0);
	}
	for (a = 1; i->argv[a]; a++)
	{
		x = _strchr1(i->argv[a], '=');
		if (x)
			set_alias(i, i->argv[a]);
		else
			print_alias(node_starts_with1(i->alias, i->argv[a], '='));
	}

	return (0);
}
