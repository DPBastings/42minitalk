/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   byteops.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:09:36 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/09 12:09:44 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BYTEOPS_H
# define BYTEOPS_H

# include <stddef.h>

unsigned char	bitshift_l(void *bytes, size_t size);
unsigned char	bitshift_r(void *bytes, size_t size);
void			bitset_l(void *bytes, size_t size, unsigned char bit);
void			bitset_r(void *byets, size_t size, unsigned char bit);

#endif
