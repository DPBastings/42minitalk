/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   comm.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:09:53 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/27 12:22:07 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMM_H
# define COMM_H

# include <stddef.h>
# include <sys/types.h>

# define USLEEP_SEND	150
# define SLEEP_TIMEOUT	5

typedef struct s_pheader
{
	pid_t	origin;
	size_t	len;
}	t_pheader;

typedef struct s_packet
{
	t_pheader	header;
	char		*data;
}	t_packet;

typedef struct s_inbox
{
	size_t		bits;
	t_packet	*packet;
}	t_inbox;

void		send_bits(pid_t process, void *data, size_t width);
void		send(pid_t process, t_packet *packet);
void		receive(void);
t_inbox		*inbox_new(void);
void		inbox_init(void);
void		inbox_process(void);

void		mnt_error(char const *message);

#endif
