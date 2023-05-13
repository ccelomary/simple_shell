#include "../shell.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
	char *buffer = NULL;

	buffer = _realloc(buffer, 0, 15);
	strcpy(buffer, "Mohamed Elomary");
	printf("%s\n", buffer);
	buffer = _realloc(buffer, 15, 25);
	strcpy(buffer + 15, " El omary");
	printf("%s\n", buffer);
	free(buffer);
	return (0);
}
