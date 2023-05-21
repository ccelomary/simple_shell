#include "../shell.h"
#include <stdio.h>

int main(void)
{
	char **s = _split("echo hello world > file | ls -la ns; echo hello world | hi mmm", "|");
	char **v = s;
	while (*v)
	{
		printf("%s\n", *v);
		v++;
	}
	_free_split(&s);
	return (0);
}
