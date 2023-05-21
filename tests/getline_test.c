#include "../shell.h"
#include <stdio.h>

int main(void)
{
	char *line;
	int ret;

	ret = 1;
	while (ret)
	{
		ret = _getline(&line);
		if (!line)
			break;
		printf("-> %s\n", line);
		free(line);
	}
	return (0);
}
