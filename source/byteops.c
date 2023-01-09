/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   byteops.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:15:43 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/09 12:15:45 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "byteops.h"
#include <limits.h>

unsigned char	bitshift_l(void *bytes, size_t size)
{
	unsigned char	*byte;
	unsigned char	next_bit;
	unsigned char	ret;

	byte = bytes;
	ret = *byte & (1 << (CHAR_BIT - 1));
	if (size == 0)
		return (ret);
	while (size--)
	{
		if (size && (byte[1] & (1 << (CHAR_BIT - 1))))
			next_bit = 1;
		else
			next_bit = 0;
		*byte <<= 1;
		*byte |= next_bit;
		byte++;
	}
	return (ret);
}

unsigned char	bitshift_r(void *bytes, size_t size)
{
	unsigned char	*byte;
	unsigned char	prev_bit;
	unsigned char	ret;

	byte = bytes + size - 1;
	ret = *byte & 1;
	if (size == 0)
		return (ret);
	while (size--)
	{
		if (size && (byte[-1] & 1))
			prev_bit = 1;
		else
			prev_bit = 0;
		*byte >>= 1;
		*byte-- |= prev_bit;
	}
	return (ret);
}

void	bitset_l(void *bytes, size_t size, unsigned char bit)
{
	unsigned char	*byte;

	if (size == 0 || bit > 1)
		return ;
	byte = bytes;
	bit <<= (CHAR_BIT - 1);
	if ((*byte & (1 << (CHAR_BIT - 1))) && bit == 0)
		*byte &= ~bit;
	else
		*byte |= bit;
}

void	bitset_r(void *bytes, size_t size, unsigned char bit)
{
	unsigned char	*byte;

	if (size == 0 || bit > 1)
		return ;
	byte = bytes + size - 1;
	if ((*byte & 1) && bit == 0)
		*byte &= ~bit;
	else
		*byte |= bit;
}
