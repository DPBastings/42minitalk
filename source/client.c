#include "comm.h"
#include "libft.h"
#include "libftprintf.h"
#include <sys/types.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	pid_t		server_pid;
	t_packet	packet;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		packet.self_pid = getpid();
		packet.len = ft_strlen(argv[2]);
		packet.data = argv[2];
		send(server_pid, &packet);
	}
	else
		ft_printf("Usage: client [server PID] [string].\n");
	return (0);
}
