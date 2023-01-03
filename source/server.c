#include "libftprintf.h"
#include <sys/types.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;
	
	pid = getpid();
	ft_printf("Welcome to Minitalk! PID: [%d]\n", pid);
	return (0);
}
