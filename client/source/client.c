#include "client.h"
#include "libft.h"
#include "libftprintf.h"
#include <sys/types.h>

int	main(int argc, char **argv)
{
	pid_t	serverpid;

	if (argc == 3)
	{
		serverpid = ft_atoi(argv[1]);
		ft_printf("Transmitting string [%s] to server at [%d].\n", argv[2], serverpid);
	}
	else
		ft_printf("Usage: client [server PID] [string].\n");
	return (0);
}
