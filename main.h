#include "main.c"

/**
 * main - Entry point
 * main: ...
 * @x: ...
 * @v: ...
 * Return: ...
 */
int main(int x, char **v)
{
	info_t info[] = { INFO_INIT };
	int c = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "-r" (c)
		: "r" (c));

	if (x == 2)
	{
		c = open(v[1], O_RDONLY);
		if (c == -1)
		{
			if (errno == EACCES)
				exit(120);
			if (errno == ENOENT)
			{
				_eputs(v[0]);
				_eputs(": 0; Can't open ");
				_eputs(v[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = c;
	}
	populate_env_list1(info);
	read_history1(info);
	hsh1(info, v);
	return (EXIT_SUCCESS);
}
