#include "shell.h"

/**
 * _strcpy - copy the string
 * @str2: string to copy in
 * @str1: string to be copied
 *
 * Return: str2 pointer
 */
char *_strcpy(char *str2, char *str1)
{
	int i = 0;

	if (str2 == str1 || str1 == 0)
		return (str2);
	while (str1[i])
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = 0;
	return (str2);
}

/**
 * _strdup - returns a pointer to the duplicated string
 * @str: string to be duplicated
 *
 * Return: duplicated string pointer
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - write  string to stdout up to
 * but not including the null character.
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes a single character to the standard output stream
 * @ch: The character to print
 *
 * Return: 1 success else -1 is returned
 */
int _putchar(char ch)
{
	static int i;
	static char bf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, bf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		bf[i++] = ch;
	return (1);
}
