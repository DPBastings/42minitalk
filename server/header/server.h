#ifndef SERVER_H
# define SERVER_H

# include <sys/types.h>

typedef struct s_session
{
	pid_t	client;
	char	*data;
}	t_session;

#endif
