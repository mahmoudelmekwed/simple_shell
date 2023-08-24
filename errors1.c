#include "shell.h"

/**
 * erratoi - Entry point
 * erratoi: ...
 * @x: ...
 * Return: ...
 */
int erratoi(char *x)
{
	int l = 0;
	unsigned int res = 0;

	if (*x == '+')
		x++;
	for (l = 0; x[l] != '\0'; l++)
	{
		if (x[l] >= '0' && x[l] <= '9')
		{
			res *= 10;
			res += (x[l] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * print_error - Entry point
 * print_error: ...
 * @w: ..
 * @x: ..
 * Return: ...
 */
void print_error(info_t *w, char *x)
{
	_eputs(w->fname);
	_eputs(": ");
	print_d(w->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(w->argv[0]);
	_eputs(": ");
	_eputs(x);
}

/**
 * print_d - Entry point
 * print_d: ...
 * @i: ...
 * @fg: ..
 * Return: ...
 */
int print_d(int i, int fg)
{
	int (*__putchar)(char) = _putchar;
	int z, c = 0;
	unsigned int _ab_, cu;

	if (fg == STDERR_FILENO)
		__putchar = _eputchar;
	if (i < 0)
	{
		_ab_ = -i;
		__putchar('-');
		c++;
	}
	else
		_ab_ = i;
	cu = _ab_;
	for (z = 1000000000; z > 1; z /= 10)
	{
		if (_ab_ / z)
		{
			__putchar('0' + cu / z);
			c++;
		}
		cu %= z;
	}
	__putchar('0' + cu);
	c++;
	return (c);
}

/**
 * convert_number - Entry point
 * convert_number: ...
 * @n: ...
 * @b: ...
 * @f: ...
 * Return: ...
 */
char *convert_number(long int n, int b, int f)
{
	static char *arr;
	static char buff[50];
	char s = 0;
	char *p;
	unsigned long x = n;

	if (!(f & CONVERT_UNSIGNED) && n < 0)
	{
		x = -n;
		s = '-';
	}
	arr = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buff[49];
	*p = '\0';

	do {
		*--p = arr[x % b];
		x /= b;
	} while (x != 0);

	if (s)
		*--p = s;
	return (p);
}

/**
 * remove_comments - Entry point
 * remove_comments: ...
 * @b: ...
 * Return: ...
 */
void remove_comments(char *b)
{
	int x;

	for (x = 0; b[x] != '\0'; x++)
		if (b[x] == 'a' && (!x || b[x - 1] == ' '))
		{
			b[x] = '\0';
			break;
		}
}

