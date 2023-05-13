#include "../shell.h"
#include <stdio.h>

int main(void)
{
	char **s = _split("hello||world|again|and&&again&&", "&&");
	char **v = s;
	while (*v)
	{
		printf("%s\n", *v);
		v++;
	}
	_free_split(&s);
	return (0);
}
