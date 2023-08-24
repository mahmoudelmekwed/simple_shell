#include "shell.h"

/**
 * strtow - Entry point
 * strtow: ..
 * @s: ..
 * @dc: ..
 * Return: ..
 */

char **strtow(char *s, char *dc)
{
	int x, j, k, m, numwords = 0;
	char **str;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (!dc)
		dc = " ";
	for (x = 0; s[x] != '\0'; x++)
		if (!is_delim(s[x], dc) && (is_delim(s[x + 1], dc) || !s[x + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	str = malloc((1 + numwords) * sizeof(char *));
	if (!str)
		return (NULL);
	for (x = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(s[x], dc))
			x++;
		k = 0;
		while (!is_delim(s[x + k], dc) && s[x + k])
			k++;
		str[j] = malloc((k + 1) * sizeof(char));
		if (!str[j])
		{
			for (k = 0; k < j; k++)
				free(str[k]);
			free(str);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			str[j][m] = s[x++];
		str[j][m] = 0;
	}
	str[j] = NULL;
	return (str);
}

/**
 * strtow2 - Entry point
 * strtow2: splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int i, y, k, m, num = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
				    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			num++;
	if (num == 0)
		return (NULL);
	s = malloc((1 + num) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, y = 0; y < num; y++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[y] = malloc((k + 1) * sizeof(char));
		if (!s[y])
		{
			for (k = 0; k < y; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[y][m] = str[i++];
		s[y][m] = 0;
	}
	s[y] = NULL;
	return (s);
}
