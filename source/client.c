/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:15:54 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/27 12:27:17 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "comm.h"
#include "libft.h"
#include "libftprintf.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static void	catch_response(int signum)
{
	(void) signum;
	ft_printf("Message acknowledged.\n");
}

int	main(int argc, char **argv)
{
	pid_t			server_pid;
	t_packet		packet;

	if (argc != 3)
		mnt_error("Usage: client [server PID] [string].");
	signal(SIGUSR1, catch_response);
	server_pid = ft_atoi(argv[1]);
	packet.header.origin = getpid();
	packet.header.len = ft_strlen(argv[2]);
	packet.data = argv[2];
	if (argv[2][0] != '\0')
	{
		send(server_pid, &packet);
		if (!sleep(TIMEOUT))
			mnt_error("Error: timeout.");
	}
	return (0);
}
