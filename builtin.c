#include "shell.h"

/**
 * _myexit - exits the shell
 * @i: Structure containing potential arguments.
 * maintain function prototype.
 * Return: exits.
 * (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *i)
{
	int exit;

	if (i->argv[1]) /* If exit arguement exists*/
	{
		exit = erratoi(i->argv[1]);
		if (exit == -1)
		{
			i->status = 2;
			print_error(i, "Illegal number: ");
			_eputs(i->argv[1]);
			_eputchar('\n');
			return (1);
		}
		i->err_num = erratoi(i->argv[1]);
		return (-2);
	}
	i->err_num = -1;
	return (-2);
}

/**
 * _mycd - Changes current directory of process
 * @i: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: 0
 */
int _mycd(info_t *i)
{
	char *x, *dir, buffer[1024];
	int chdir_ret;

	x = getcwd(buffer, 1024);
	if (!x)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!i->argv[1])
	{
		dir = _getenv(i, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(i, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(i->argv[1], "-") == 0)
	{
		if (!_getenv(i, "OLDPWD="))
		{
			_puts(x);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(i, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(i, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(i->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(i, "can't cd to ");
		_puts(i->argv[1]), _putchar('\n');
	}
	else
	{
		_setenv(i, "OLDPWD", _getenv(i, "PWD="));
		_setenv(i, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - Changes current directory of process
 * @i: Structure containing potential arguments. Used to maintain
 * Constant function prototype.
 * Return: 0
 */
int _myhelp(info_t *i)
{
	char **arg_arr;

	arg_arr = i->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arr); /* temp att_unused workaround */
	return (0);
}
