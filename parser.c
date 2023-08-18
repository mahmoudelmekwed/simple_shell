#include "shell.h"

/**
 * is_cmd - ..
 * @i: info struct
 * @p: file path
 *
 * Return: 1 true, else 0
 */
int is_cmd(info_t *i, char *p)
{
	struct stat st;

	(void)i;
	if (!p || stat(p, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - char duplication
 * @pstr: string path
 * @f: first index
 * @e: end index
 *
 * Return: new buffer pointer
 */
char *dup_chars(char *pstr, int f, int  e)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = f; i < e; i++)
		if (pstr[i] != ':')
			buf[k++] = pstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - ..
 * @i: ..
 * @pstr: ..
 * @cmd: ..
 *
 * Return: ..
 */
char *find_path(info_t *i, char *pstr, char *cmd)
{
	int j = 0, cu_pos = 0;
	char *path;

	if (!pstr)
		return (NULL);
	if ((_strlen1(cmd) > 2) && starts_with1(cmd, "./"))
	{
		if (is_cmd(i, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pstr[j] || pstr[j] == ':')
		{
			path = dup_chars(pstr, cu_pos, j);
			if (!*path)
				_strcat1(path, cmd);
			else
			{
				_strcat1(path, "/");
				_strcat1(path, cmd);
			}
			if (is_cmd(i, path))
				return (path);
			if (!pstr[j])
				break;
			cu_pos = j;
		}
		j++;
	}
	return (NULL);
}
