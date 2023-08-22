#include "shell.h"

/**
 * bfree - Entry point
 * bfree: ...
 * @hh: ..
 * Return: ...
 */
int bfree(void **hh)
{
	if (hh && *hh)
	{
		free(*hh);
		*hh = NULL;
		return (1);
	}
	return (0);
}
