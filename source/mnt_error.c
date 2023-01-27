/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mnt_error.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 15:11:15 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/27 12:21:26 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "comm.h"
#include "libftprintf.h"
#include <stdlib.h>

void	mnt_error(char const *message)
{
	ft_dprintf(2, "%s\n", message);
	exit(EXIT_FAILURE);
}
