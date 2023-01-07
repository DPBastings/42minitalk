#include "comm.h"
#include "byteops.h"
#include "libft.h"
#include "libftprintf.h"
#include <limits.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

extern t_inbox	*inbox;

void	catch_response(int signum)
{
	(void) signum;
	ft_printf("Message acknowledged.\n");
}

void	catch_message(int signum)
{
	signal(signum, catch_message);
	inbox->bits++;
	if (inbox->bits <= sizeof(t_pheader) * 8)
	{
		bitshift_l(&(inbox->packet->header), sizeof(t_pheader));
		if (signum == SIGUSR2)
			bitset_r(&(inbox->packet->header), sizeof(t_pheader), 1);
	}	
	if (inbox->bits == sizeof(t_pheader) * 8)
	{
		inbox->packet->data = malloc(inbox->packet->header.len + 1);
		if (inbox->packet->data == NULL)
			exit(EXIT_FAILURE);
		inbox->packet->data[inbox->packet->header.len] = '\0';
		ft_printf("\nReceiving: %d chars from [%d].\n", inbox->packet->header.len, inbox->packet->header.origin);
	}
	if (inbox->bits > sizeof(t_pheader) * 8)
	{
		bitshift_l(inbox->packet->data, inbox->packet->header.len);
		if (signum == SIGUSR2)
			bitset_r(inbox->packet->data, inbox->packet->header.len, 1);
	}	
	if (inbox->bits == (sizeof(t_pheader) + inbox->packet->header.len) * 8)
		inbox_process();
}

void inbox_init(void)
{
	inbox->bits = 0;
	ft_bzero(inbox->packet, sizeof(t_packet));
}

t_inbox	*inbox_new(void)
{
	t_inbox	*new;

	new = malloc(sizeof(t_inbox));
	if (new == NULL)
		return (NULL);
	new->packet = malloc(sizeof(t_packet));
	if (new->packet == NULL)
		return (free(new), NULL);
	return (new);
}

void	receive(void)
{
	signal(SIGUSR1, catch_message);
	signal(SIGUSR2, catch_message);
	while (1)
		pause();
}
