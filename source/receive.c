#include "comm.h"
#include "byteops.h"
#include "libft.h"
#include "libftprintf.h"
#include <limits.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

extern t_inbox	*inbox;

static void	catch_data(int signum);
static void	catch_header(int signum);

static void	catch_data(int signum)
{
	unsigned char	*byte;
	unsigned char	mask;
	
	signal(signum, catch_data);
	inbox->bits++;
	byte = (unsigned char *)inbox->packet->data + ((inbox->bits - 1) / 8);
	mask = (1 << (7 - (inbox->bits - 1) % 8));
	if (signum == SIGUSR2)
		*byte |= mask;
	if (inbox->bits == inbox->packet->header.len * 8)
	{
		inbox_process();
		signal(SIGUSR1, catch_header);
		signal(SIGUSR2, catch_header);
	}
}

static void	catch_header(int signum)
{
	signal(signum, catch_header);
	inbox->bits++;
	bitshift_l(&(inbox->packet->header), sizeof(t_pheader));
	if (signum == SIGUSR2)
		bitset_r(&(inbox->packet->header), sizeof(t_pheader), 1);	
	if (inbox->bits == sizeof(t_pheader) * 8)
	{
		inbox->bits = 0;
		signal(SIGUSR1, catch_data);
		signal(SIGUSR2, catch_data);
		inbox->packet->data = ft_calloc(inbox->packet->header.len + 1, sizeof(char));
		if (inbox->packet->data == NULL)
			exit(EXIT_FAILURE);
		ft_printf("\nReceiving: %d chars from [%d].\n", inbox->packet->header.len, inbox->packet->header.origin);
	}
}

void	receive(void)
{
	signal(SIGUSR1, catch_header);
	signal(SIGUSR2, catch_header);
	while (1)
		pause();
}
