/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   receive.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:19:05 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/27 12:16:25 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "comm.h"
#include "byteops.h"
#include "libft.h"
#include "libftprintf.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

extern t_inbox	*g_inbox;

static void	catch_data(int signum);
static void	catch_header(int signum);
static void	set_handlers(void (*handler)(int));

static void	catch_data(int signum)
{
	unsigned char	*byte;
	unsigned char	mask;

	g_inbox->bits++;
	byte = (unsigned char *)g_inbox->packet->data + ((g_inbox->bits - 1) / 8);
	mask = (1 << (7 - (g_inbox->bits - 1) % 8));
	if (signum == SIGUSR2)
		*byte |= mask;
	if (g_inbox->bits == g_inbox->packet->header.len * 8)
	{
		inbox_process();
		set_handlers(catch_header);
	}
}

static void	catch_header(int signum)
{
	t_pheader	*header;

	header = &g_inbox->packet->header;
	g_inbox->bits++;
	bitshift_l(header, sizeof(t_pheader));
	if (signum == SIGUSR2)
		bitset_r(header, sizeof(t_pheader), 1);
	if (g_inbox->bits == sizeof(t_pheader) * 8)
	{
		set_handlers(catch_data);
		g_inbox->bits = 0;
		g_inbox->packet->data = ft_calloc(header->len + 1, sizeof(char));
		if (g_inbox->packet->data == NULL)
		{
			free(g_inbox);
			mnt_error("Error: couldn't allocate message buffer.");
		}
	}
}

static void	set_handlers(void (*handler)(int))
{
	struct sigaction	action;
	struct sigaction	old_action;

	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, &old_action);
	sigaction(SIGUSR2, &action, &old_action);
}

void	receive(void)
{
	set_handlers(catch_header);
	while (1)
		pause();
}
