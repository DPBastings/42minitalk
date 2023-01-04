#ifndef COMM_H
# define COMM_H

#include <stddef.h>
#include <sys/types.h>

typedef struct s_packet
{
	pid_t	self_pid;
	size_t	len;
	char	*data;
}	t_packet;

void	send_bits(pid_t process, void *data, size_t width);
void	send(pid_t process, t_packet *packet);

#endif
