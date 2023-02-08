/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   send.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:48:51 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/30 15:50:24 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "comm.h"
#include "byteops.h"
#include "libft.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void	send_bytes(pid_t process, void *bytes, size_t size)
{
	unsigned char	*byte;
	unsigned char	mask;

	if (bytes == NULL)
		return ;
	byte = bytes;
	while (size--)
	{
		mask = (1 << 7);
		while (mask)
		{
			if (mask & *byte)
				kill(process, SIGUSR2);
			else
				kill(process, SIGUSR1);
			bitshift_r(&mask, sizeof(unsigned char));
			usleep(USLEEP_SEND);
		}
		byte++;
	}
}

void	send(pid_t process, t_packet *packet)
{
	if (process == 0 || process == -1 || kill(process, 0) == -1)
		mnt_error("Error: invalid server PID");
	send_bytes(process, &packet->header, sizeof(t_pheader));
	send_bytes(process, packet->data, packet->header.len);
}
