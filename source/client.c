#include "comm.h"
#include "libft.h"
#include "libftprintf.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static void	catch_response(int signum)
{
	(void) signum;
	ft_printf("Message acknowledged.\n");
}

int	main(int argc, char **argv)
{
	pid_t			server_pid;
	t_packet		packet;

	if (argc == 3)
	{
		signal(SIGUSR1, catch_response);
		server_pid = ft_atoi(argv[1]);
		packet.header.origin = getpid();
		packet.header.len = ft_strlen(argv[2]);
		packet.data = argv[2];
		send(server_pid, &packet);
		if (!sleep(TIMEOUT))
			ft_printf("Time out.\n");
	}
	else
		ft_dprintf(2, "Usage: client [server PID] [string].\n");
	return (0);
}
