#include "client.h"
#include "libft.h"
#include "libftprintf.h"
#include <sys/types.h>

int	main(int argc, char **argv)
{
	pid_t	serverpid;

	if (argc == 3)
	{
		ft_printf("Transmitting string [%s] to server at [%d].\n", argv[2], argv[1]);
		serverpid = ft_atoi(argv[1]);
	}
	return (0);
}
