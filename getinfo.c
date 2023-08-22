#include "shell.h"

/**
 * clear_info - ..
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
 * set_info - ..
 * @i: struct address
 * @v: argument vector
 */
void set_info(info_t *i, char **v)
{
	int j = 0;

	i->fname = v[0];
	if (i->arg)
	{
		i->argv = strtow(i->arg, " \t");
		if (!i->argv)
		{
			i->argv = malloc(sizeof(char *) * 2);
			if (i->argv)
			{
				i->argv[0] = _strdup(i->arg);
				i->argv[1] = NULL;
			}
		}
		for (j = 0; i->argv && i->argv[j]; j++)
			;
		i->argc = j;

		replace_alias(i);
		replace_vars(i);
	}
}

/**
 * free_info - free info_t struct
 * @i: struct address
 * @a: true if freeing all fields
 */
void free_info(info_t *i, int a)
{
	ffree(i->argv);
	i->argv = NULL;
	i->path = NULL;
	if (a)
	{
		if (!i->cmd_buf)
			free(i->arg);
		if (i->env)
			free_list(&(i->env));
		if (i->history)
			free_list(&(i->history));
		if (i->alias)
			free_list(&(i->alias));
		ffree(i->environ);
			i->environ = NULL;
		bfree((void **)i->cmd_buf);
		if (i->readfd > 2)
			close(i->readfd);
		_putchar(BUF_FLUSH);
	}
}
