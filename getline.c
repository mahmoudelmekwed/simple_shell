#include "shell.h"

/**
 * input_buf - ..
 * @i: parameter struct
 * @bf: buffer
 * @l: len var
 *
 * Return: bytes
 */
ssize_t input_buf(info_t *i, char **bf, size_t *l)
{
	ssize_t r = 0;
	size_t l_p = 0;

	if (!*l)
	{
		free(*bf);
		*bf = NULL;
		signal(SIGINT, siginhandler);
#if USE_GETLINE
		r = getline(bf, &l_p, stdin);
#else
		r = _getline(i, bf, &l_p);
#endif
		if (r > 0)
		{
			if ((*bf)[r - 1] == '\n')
			{
				(*bf)[r - 1] = '\0';
				r--;
			}
			i->linecount_flag = 1;
			remove_comments(*bf);
			build_history_list(i, *bf, i->histcount++);
			{
				*l = r;
				i->cmd_buf = bf;
			}
		}
	}
	return (r);
}

/**
 * get_input - line minus newline
 * @i: parameter struct
 *
 * Return: bytes
 */
ssize_t get_input(info_t *i)
{
	static char *bf;
	static size_t x, j, ln;
	ssize_t r = 0;
	char **bf_p = &(i->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(i, &bf, &ln);
	if (r == -1)
		return (-1);
	if (ln)
	{
		j = x;
		p = bf + x;

		check_chain(i, bf, &j, x, ln);
		while (j < ln)
		{
			if (is_chain(i, bf, &j))
				break;
			j++;
		}

		x = j + 1;
		if (x >= ln)
		{
			x = ln = 0;
			i->cmd_buf_type = CMD_NORM;
		}
		return (_strlen(p));
	}

	*bf_p = bf;
	return (r);
}

/**
 * read_bf - read buffer
 * @i: parameter struct
 * @bf: buffer
 * @s: size
 * Return: r
 */
ssize_t read_bf(info_t *i, char *bf, size_t *s)
{
	ssize_t r = 0;

	if (*s)
		return (0);
	r = read(i->readfd, bf, READ_BUF_SIZE);
	if (r >= 0)
		*s = r;
	return (r);
}

/**
 * _getline - get next line from STDIN
 * @i: parameter struct
 * @bf: pointer to buffer
 * @ln: size of preallocated ptr buffer
 *
 * Return: s
 */
int _getline(info_t *i, char **bf, size_t *ln)
{
	static char buf[READ_BUF_SIZE];
	static size_t x, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *bf;
	if (p && ln)
		s = *ln;
	if (x == len)
		x = len = 0;

	r = read_bf(i, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + x, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + x, k - x);
	else
		_strncpy(new_p, buf + x, k - x + 1);

	s += k - x;
	x = k;
	p = new_p;

	if (ln)
		*ln = s;
	*bf = p;
	return (s);
}

/**
 * siginhandler - blocks ctrl-C
 * @si:..
 *
 * Return: ..
 */
void siginhandler(__attribute__((unused))int si)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
