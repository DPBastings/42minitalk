/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 15:11:15 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/23 15:12:22 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "comm.h"
#include "libftprintf.h"
#include <stdlib.h>

void	ft_exit(char const *message, int status)
{
	ft_dprintf(2, "%s\n", message);
	exit(status);
}
