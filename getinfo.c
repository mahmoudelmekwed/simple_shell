#include "shell.h"

/**
 * clear_info1 - ..
 * @i: Struct address
 */
void clear_info(info_t *i)
{
	i->arg = NULL;
	i->argv = NULL;
	i->path = NULL;
	i->argc = 0;
}

/**
 * set_info1 - ..
 * @i: struct address
 * @v: argument vector
 */
void set_info1(info_t *i, char **v)
{
	int j = 0;

	i->fname = v[0];
	if (i->arg)
	{
		i->argv = strtow1(i->arg, " \t");
		if (!i->argv)
		{
			i->argv = malloc(sizeof(char *) * 2);
			if (i->argv)
			{
				i->argv[0] = _strdup1(i->arg);
				i->argv[1] = NULL;
			}
		}
		for (j = 0; i->argv && i->argv[j]; j++)
			;
		i->argc = j;

		replace_alias1(i);
		replace_vars1(i);
	}
}

/**
 * free_info1 - free info_t struct
 * @i: struct address
 * @a: true if freeing all fields
 */
void free_info1(info_t *i, int a)
{
	ffree1(i->argv);
	i->argv = NULL;
	i->path = NULL;
	if (a)
	{
		if (!i->cmd_buf)
			free(i->arg);
		if (i->env)
			free_list1(&(i->env));
		if (i->history)
			free_list1(&(i->history));
		if (i->alias)
			free_list1(&(i->alias));
		ffree1(i->environ);
			i->environ = NULL;
		bfree1((void **)i->cmd_buf);
		if (i->readfd > 2)
			close(i->readfd);
		_putchar1(BUF_FLUSH);
	}
}
