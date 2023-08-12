#include "shell.h"

/**
 * bfree1 - Entry point
 * bfree1: ...
 * @hh: ..
 * Return: ...
 */
int bfree1(void **hh)
{
	if (hh && *hh)
	{
		free(*hh);
		*hh = NULL;
		return (1);
	}
	return (0);
}
