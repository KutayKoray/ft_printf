/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:33:16 by kkoray            #+#    #+#             */
/*   Updated: 2024/11/10 15:33:17 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_uitoa(unsigned long value, int base)
{
	size_t	i;
	size_t	length;
	char	*buffer;
	int		remainder;

	i = 0;
	length = get_length(value, base);
	buffer = malloc((length + 1) * sizeof(char));
	if (value == 0)
	{
		buffer[i++] = '0';
		buffer[i] = '\0';
		return (buffer);
	}
	while (value != 0)
	{
		remainder = value % base;
		if (remainder > 9)
			buffer[i++] = remainder - 10 + 'a';
		else
			buffer[i++] = remainder + '0';
		value = value / base;
	}
	buffer[i] = '\0';
	reverse(buffer, i);
	return (buffer);
}
