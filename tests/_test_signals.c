#include <signal.h>
#include <unistd.h>

void _handle_signal(int sig)
{
	(void)sig;

	write(1, "CTRL-C\n", 7);
}

int main(void)
{
	signal(SIGINT, _handle_signal);
	while (1)
	{
		sleep(1);
	}
}
