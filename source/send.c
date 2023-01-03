#include "comm.h"
#include "libft.h"
#include "libftprintf.h"
#include <sys/types.h>
#include <signal.h>

void	send_bits(void *data, size_t width)
{
	size_t	index;
	long	bits;

	index = 0;
	bits = *(long *)data;
	while (index++ < width * 8)
	{
		if (bits & 1)
			ft_printf("1");
		else
			ft_printf("0");
		bits >>= 1;
	}
}

void	send(pid_t pid, char *data)
{
	size_t	len;

	len = ft_strlen(data);
	send_bits(&pid, sizeof(pid_t));
	send_bits(&len, sizeof(size_t));
	while (*data)
		send_bits(data++, sizeof(char));
}
