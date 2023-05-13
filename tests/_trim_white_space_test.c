#include "../shell.h"
#include <stdio.h>

int main(void)
{
	char *s = _trim_white_space("     hellow   woorld    again > anywhere >> everywhere");
	if (!s)
		return (1);
	printf("%s\n", s);
	free(s);
	return (0);
}
