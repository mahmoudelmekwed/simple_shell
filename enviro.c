#include "shell.h"

/**
 * _myenv - prints a copy of the environment
 * @i: Structure containing potential argument
 *
 * Return: 0
 */
int _myenv(info_t *i)
{
	print_list_str1(i->env);
	return (0);
}

/**
 * _getenv1 - Gets an environmental variable from the path.
 * @i: ..
 * @var: Envrionmental variable name
 *
 * Return: value
 */
char *_getenv1(info_t *i, const char *var)
{
	list_t *n = i->env;
	char *p;

	while (n)
	{
		p = starts_with1(n->str, var);
		if (p && *p)
			return (p);
		n = n->next;
	}
	return (NULL);
}

/**
 * _mysetenv -..
 *
 * @i: potential arguments.
 *        constant function prototype.
 *  Return: 0
 */
int _mysetenv(info_t *i)
{
	if (i->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(i, i->argv[1], i->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv1 - Remove environment var
 * @i: ..
 *
 * Return: 0
 */
int _myunsetenv1(info_t *i)
{
	int j;

	if (i->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= i->argc; j++)
		_unsetenv(i, i->argv[j]);

	return (0);
}

/**
 * populate_env_list1 - populates env linked list
 * @res: ..
 * Return: 0
 */
int populate_env_list1(info_t *res)
{
	list_t *n = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end1(&n, environ[i], 0);
	res->env = n;
	return (0);
}
