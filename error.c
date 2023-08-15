#include "shell.h"

/**
 * _eputs - Print input string
 * @str: string
 *
 * Return: ..
 */
void _eputs(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_eputchar(str[x]);
		x++;
	}
}

/**
 * _eputchar - ..
 * @ch: Character to be printed
 *
 * Return: success 1.
 * Error, -1.
 */
int _eputchar(char ch)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buf, x);
		x = 0;
	}
	if (ch != BUF_FLUSH)
		buf[x++] = ch;
	return (1);
}

/**
 * _putfd - writes ch to fd
 * @ch: Character
 * @fs: Filedescriptor
 *
 * Return: 1.
 * Error, -1.
 */
int _putfd(char ch, int fs)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(fs, buf, x);
		x = 0;
	}
	if (ch != BUF_FLUSH)
		buf[x++] = ch;
	return (1);
}

/**
 * _putsfd - Prints input string
 * @str: the string to be printed
 * @fs: Filedescriptor
 *
 * Return: Number of chars
 */
int _putsfd(char *str, int fs)
{
	int x = 0;

	if (!str)
		return (0);
	while (*str)
	{
		x += _putfd(*str++, fs);
	}
	return (x);
}
