#include "comm.h"
#include "libft.h"
#include "libftprintf.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

t_inbox	*inbox = NULL;

void	inbox_process(void)
{
	ft_printf("%s\n", inbox->packet->data);
	free(inbox->packet->data);
	usleep(500);
	kill(inbox->packet->header.origin, SIGUSR1);
	inbox_init();
}

void	inbox_init(void)
{
	inbox->bits = 0;
	ft_bzero(inbox->packet, sizeof(t_packet));
}

t_inbox *inbox_new(void)
{
	t_inbox *new;
	
	new = malloc(sizeof(t_inbox));
	if (new == NULL)
		return (NULL);
	new->packet = malloc(sizeof(t_packet));
	if (new->packet == NULL)
		return (free(new), NULL);
	return (new);
}

int	main(void)
{
	pid_t	pid;
	
	pid = getpid();
	ft_printf("Welcome to Minitalk! PID: [%d]\n", pid);
	inbox = inbox_new();
	inbox_init();
	receive();
	return (0);
}
