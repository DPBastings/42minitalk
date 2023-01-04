#include "comm.h"
#include "libft.h"
#include "libftprintf.h"
#include <sys/types.h>
#include <signal.h>

//Check whether the destination process actually exists; throw an error if it doesn't.

void	send_bytes(pid_t process, void *bytes, size_t n)
{
	size_t	index;
	long	bits;

	index = 0;
	bits = *(long *)bytes;
	while (index++ < n * 8)
	{
		if (bits & 1)
			kill(process, SIGUSR2);
		else
			kill(process, SIGUSR1);
		bits >>= 1;
	}
}

void	send(pid_t process, t_packet *packet)
{
	ft_printf("Transmitting string [%s] to server at [%d].\n", packet->data, process);
	send_bytes(process, &(packet->self_pid), sizeof(pid_t));
	send_bytes(process, &(packet->len), sizeof(size_t));
	while (*(packet->data))
		send_bytes(process, (packet->data)++, sizeof(char));
}
