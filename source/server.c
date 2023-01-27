/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:44:34 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/27 12:24:56 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "comm.h"
#include "libft.h"
#include "libftprintf.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

t_inbox	*g_inbox = NULL;

void	inbox_process(void)
{
	ft_printf("%s\n", g_inbox->packet->data);
	free(g_inbox->packet->data);
	usleep(500);
	kill(g_inbox->packet->header.origin, SIGUSR1);
	inbox_init();
}

void	inbox_init(void)
{
	g_inbox->bits = 0;
	ft_bzero(g_inbox->packet, sizeof(t_packet));
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

int	main(void)
{
	pid_t	pid;

	g_inbox = inbox_new();
	if (g_inbox == NULL)
		mnt_error("Error: couldn't allocate inbox.");
	inbox_init();
	pid = getpid();
	ft_printf("Welcome to Minitalk! PID: [%d]\n", pid);
	receive();
	return (0);
}
