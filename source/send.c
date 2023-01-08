#include "comm.h"
#include "byteops.h"
#include "libft.h"
#include "libftprintf.h"
#include "limits.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

//Check whether the destination process actually exists; throw an error if it doesn't.

void	send_bytes(pid_t process, void *bytes, size_t size)
{
	unsigned char	*byte;
	unsigned char	mask;

	byte = bytes;
	while (size--)
	{
		mask = (1 << (CHAR_BIT - 1));
		while (mask)
		{
			if (mask & *byte)
				kill(process, SIGUSR2);
			else
				kill(process, SIGUSR1);
			bitshift_r(&mask, sizeof(unsigned char));
			usleep(25);
		}
		byte++;
	}
}

void send(pid_t process, t_packet *packet)
{
	send_bytes(process, &packet->header, sizeof(t_pheader));
	send_bytes(process, packet->data, packet->header.len);
}
