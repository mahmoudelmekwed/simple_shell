#include "shell.h"

/**
 * get_environ - Entry point
 * get_environ: ..
 * @i: ...
 * Return: ..
 */
char **get_environ(info_t *i)
{
	if (!i->environ || i->env_changed)
	{
		i->environ = list_to_strings(i->env);
		i->env_changed = 0;
	}
	return (i->environ);
}

/**
 * _unsetenv - Entry point
 * _unsetenv: ....
 * @i: ...
 * @v: ..
 * Return: ..
 */
int _unsetenv(info_t *i, char *v)
{
	list_t *n = i->env;
	size_t x = 0;
	char *ptr;

	if (!n || !v)
		return (0);
	while (n)
	{
		ptr = starts_with(n->str, v);
		if (ptr && *ptr == '=')
		{
			i->env_changed = delete_node_at_index(&(i->env), x);
			x = 0;
			n = i->env;
			continue;
		}
		n = n->next;
		x++;
	}
	return (i->env_changed);
}

/**
 * _setenv - Entry point
 * _setenv: ...
 * @i: ..
 * @v: ..
 * @v2: ..
 * Return: ..
 */
int _setenv(info_t *i, char *v, char *v2)
{
	char *p = NULL;
	list_t *n;
	char *ptr;

	if (!v || !v2)
		return (0);
	p = malloc(_strlen(v) + _strlen(v2) + 2);
	if (!p)
		return (1);
	_strcpy(p, v);
	_strcat(p, "=");
	_strcat(p, v2);
	n = i->env;
	while (n)
	{
		ptr = starts_with(n->str, v);
		if (ptr && *ptr == '=')
		{
			free(n->str);
			n->str = p;
			i->env_changed = 1;
			return (0);
		}
		n = n->next;
	}
	add_node_end(&(i->env), p, 0);
	free(p);
	i->env_changed = 1;
	return (0);
}
