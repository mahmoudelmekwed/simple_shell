#include "shell.h"

/**
 **_strncpy1 - Copies string
 *@des: the destination string
 *@src: Source string
 *@no: the amount
 *Return: Concatenated str
 */
char *_strncpy1(char *des, char *src, int no)
{
	int i, j;
	char *c = des;

	i = 0;
	while (src[i] != '\0' && i < no - 1)
	{
		des[i] = src[i];
		i++;
	}
	if (i < no)
	{
		j = i;
		while (j < no)
		{
			des[j] = '\0';
			j++;
		}
	}
	return (c);
}

/**
 **_strncat1 - Concatenates two string
 *@des: First string
 *@src: Second string
 *@no: amount
 *Return: Concatenated string
 */
char *_strncat1(char *des, char *src, int no)
{
	int i, j;
	char *c = des;

	i = 0;
	j = 0;
	while (des[i] != '\0')
		i++;
	while (src[j] != '\0' && j < no)
	{
		des[i] = src[j];
		i++;
		j++;
	}
	if (j < no)
		des[i] = '\0';
	return (c);
}

/**
 **_strchr1 - ..
 *@str: String parsed
 *@c: the character
 *Return: (m)
 */
char *_strchr1(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
