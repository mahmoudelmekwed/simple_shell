#include "shell.h"

/**
 * hsh1 - Entry point
 * hsh1: ..
 * @i: ..
 * @ac: ...
 * Return: ..
 */
int hsh1(info_t *i, char **ac)
{
	ssize_t x = 0;
	int b_ret = 0;

	while (x != -1 && b_ret != -2)
	{
		clear_info1(i);
		if (interactive1(i))
			_puts1("$ ");
		_eputchar(BUF_FLUSH);
		x = get_input1(i);
		if (x != -1)
		{
			set_info1(i, ac);
			b_ret = find_builtin(i);
			if (b_ret == -1)
				find_cmd(i);
		}
		else if (interactive1(i))
			_putchar1('\n');
		free_info1(i, 0);
	}
	write_history1(i);
	free_info1(i, 1);
	if (!interactive1(i) && i->status)
		exit(i->status);
	if (b_ret == -2)
	{
		if (i->err_num == -1)
			exit(i->status);
		exit(i->err_num);
	}
	return (b_ret);
}

/**
 * find_builtin1 - Entry point
 * find_builtin1: ..
 * @i: ..
 * Return: ..
 */
int find_builtin1(info_t *i)
{
	int x, b_in_ret = -1;
	builtin_table builtintb2[] = {
		{"exit", _myexit1},
		{"env", _myenv1},
		{"help", _myhelp1},
		{"history", _myhistory1},
		{"setenv", _mysetenv1},
		{"unsetenv", _myunsetenv1},
		{"cd", _mycd1},
		{"alias", _myalias1},
		{NULL, NULL}
	};
	for (x = 0; builtintb2[x].type; x++)
		if (_strcmp1(i->argv[0], builtintb2[x].type) == 0)
		{
			i->line_count++;
			b_in_ret = builtintb2[x].func(i);
			break;
		}
	return (b_in_ret);
}

/**
 * find_cmd1 - Entry point
 * find_cmd1: ..
 * @i: ..
 * Return: ..
 */
void find_cmd1(info_t *i)
{
	char *p = NULL;
	int x, v;

	i->path = i->argv[0];
	if (i->linecount_flag == 1)
	{
		i->line_count++;
		i->linecount_flag == 0;
	}
	for (x = 0, v = 0, i->arg[x]; x++;)
		if (!is_delim1(i->arg[x], " \t\n"))
			v++;
	if (!v)
		return;
	p = find_path(i, _getenv1(i, "PATH="), i->argv[0]);
	if (!p)
	{
		i->path = p;
		fork_cmd(i);
	}
	else
	{
		if ((interactive1(i) || _getenv1(i, "PATH=")
					|| i->argv[0][0] == '/') && is_cmd(i, i->argv[0]))
			fork_cmd(i);
		else if (*(i->arg) != '\n')
		{
			i->status = 127;
			print_error1(i, "not found\n");
		}
	}
}

/**
 * fork_cmd1 - Entry point
 * fork_cmd1: ..
 * @i: ..
 * Return: ..
 */
void fork_cmd1(info_t *i)
{
	pid_t c_pid;

	c_pid = fork();
	if (c_pid == -1)
	{
		perror("Error: ");
		return;
	}
	if (c_pid == 0)
	{
		if (execve(i->path, i->argv, get_environ(i)) == -1)
		{
			free_info1(i, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(i->status));
		if (WIFEXITED(i->status))
		{
			i->status = WEXITSTATUS(i->status);
			if (i->status == 126)
				print_error1(i, "Permission denied\n");
		}
	}
}

