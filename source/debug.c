#include "libftprintf.h"
#include "comm.h"
#include "byteops.h"
#include <limits.h>

void	packet_view(t_packet *packet)
{
	ft_printf("%u\n%u\n%s\n", packet->header.origin, packet->header.len, packet->data);
}

void	binary_view(void *data, size_t size)
{
	unsigned char	*byte;
	unsigned char	mask;
	
	byte = data;
	while (size--)
	{
		mask = (1 << (CHAR_BIT - 1));
		while (mask)
		{
			if (mask & *byte)
				ft_printf("1");
			else
				ft_printf("0");
			bitshift_r(&mask, sizeof(unsigned char));
		}
		byte++;
	}
	ft_printf("\n");
}
