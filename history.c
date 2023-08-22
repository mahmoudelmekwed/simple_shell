#include "shell.h"

/**
 * get_history_file - get history file
 * @i: ..
 *
 * Return: string containing history file
 */

char *get_history_file(info_t *i)
{
	char *bf, *dir;

	dir = _getenv(i, "HOME=");
	if (!dir)
		return (NULL);
	bf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!bf)
		return (NULL);
	bf[0] = 0;
	_strcpy(bf, dir);
	_strcat(bf, "/");
	_strcat(bf, HIST_FILE);
	return (bf);
}

/**
 * write_history - appends file to existing file
 * @i: parameter struct
 *
 * Return: 1 success else -1
 */
int write_history(info_t *i)
{
	ssize_t fd;
	char *fname = get_history_file(i);
	list_t *n = NULL;

	if (!fname)
		return (-1);

	fd = open(fname, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fname);
	if (fd == -1)
		return (-1);
	for (n = i->history; n; n = n->next)
	{
		_putsfd(n->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - Read history
 * @i: Parameter struct
 *
 * Return: histcount on success, else 0
 */
int read_history(info_t *i)
{
	int j, end = 0, line = 0;
	ssize_t fd, readlen, fsize = 0;
	struct stat st;
	char *bf = NULL, *fname = get_history_file(i);

	if (!fname)
		return (0);

	fd = open(fname, O_RDONLY);
	free(fname);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	bf = malloc(sizeof(char) * (fsize + 1));
	if (!bf)
		return (0);
	readlen = read(fd, bf, fsize);
	bf[fsize] = 0;
	if (readlen <= 0)
		return (free(bf), 0);
	close(fd);
	for (j = 0; j < fsize; j++)
		if (bf[j] == '\n')
		{
			bf[j] = 0;
			build_history_list(i, bf + end, line++);
			end = j + 1;
		}
	if (end != j)
		build_history_list(i, bf + end, line++);
	free(bf);
	i->histcount = line;
	while (i->histcount-- >= HIST_MAX)
		delete_node_at_index(&(i->history), 0);
	renumber_history(i);
	return (i->histcount);
}

/**
 * build_history_list - Entry to history linked list
 * @i: Structure containing potential arguments
 * @bf: buffer
 * @line: linecount
 *
 * Return: 0
 */
int build_history_list(info_t *i, char *bf, int line)
{
	list_t *n = NULL;

	if (i->history)
		n = i->history;
	add_node_end(&n, bf, line);

	if (!i->history)
		i->history = n;
	return (0);
}

/**
 * renumber_history - number the history linked list
 * @i: ..
 *
 * Return: New history count
 */
int renumber_history(info_t *i)
{
	list_t *n = i->history;
	int j = 0;

	while (n)
	{
		n->num = j++;
		n = n->next;
	}
	return (i->histcount = j);
}
