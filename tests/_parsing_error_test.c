#include "../shell.h"
#include <stdio.h>

int main(void)
{
	printf("%d\n", _parsing_error_handler("| hello world"));
	printf("%d\n", _parsing_error_handler("hello|||world| again"));
	printf("%d\n", _parsing_error_handler("hello||world| again|"));
	printf("%d\n", _parsing_error_handler("; hello world"));
	printf("%d\n", _parsing_error_handler("hello;   world| again"));
	printf("%d\n", _parsing_error_handler("hello;world| again"));
	return (0);
}
