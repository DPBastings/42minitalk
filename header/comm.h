#ifndef COMM_H
# define COMM_H

#include <stddef.h>
#include <sys/types.h>

typedef struct s_packet
{
	pid_t	pid;
	size_t	len;
	char	*data;
}	t_packet;

void	send_bits(void *data, size_t width);
void	send(pid_t pid, char *data);

#endif
