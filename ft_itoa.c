/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:33:12 by kkoray            #+#    #+#             */
/*   Updated: 2024/11/10 15:37:37 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	reverse(char *buffer, int length)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = temp;
		start++;
		end--;
	}
}

int	handle_negative(int *value)
{
	if (*value < 0)
	{
		*value = -*value;
		return (1);
	}
	return (0);
}

unsigned long	get_length(unsigned long value, int base)
{
	unsigned long	length;

	length = 0;
	if (value == 0)
	{
		return (1);
	}
	while (value != 0)
	{
		length++;
		value = value / base;
	}
	return (length);
}

char	*ft_itoa(int value, int base)
{
	int		i;
	int		is_negative;
	int		length;
	char	*buffer;
	int		remainder;

	i = 0;
	if (value == -2147483648)
		return (buffer = malloc(12 * sizeof(char)), strcpy(buffer,
				"-2147483648"), buffer);
	is_negative = handle_negative(&value);
	length = get_length(value, base);
	buffer = malloc((length + 1 + is_negative) * sizeof(char));
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
	if (is_negative)
	{
		buffer[i++] = '-';
	}
	buffer[i] = '\0';
	reverse(buffer, i);
	return (buffer);
}
