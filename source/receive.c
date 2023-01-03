#include "comm.h"
#include <signal.h>
#include <unistd.h>

char	*receive(void)
{
	signal(SIGUSR_1, catch_usr);
	signal(SIGUSR_2, catch_usr);
	while (1)
		pause();
	return (data);
}
