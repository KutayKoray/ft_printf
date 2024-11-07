/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:52:30 by kkoray            #+#    #+#             */
/*   Updated: 2024/11/07 17:47:41 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
		va_list va;
		size_t counter;

		counter = 0;
		va_start(va, format);
		if (format[counter] == '%')
		{
			counter++;
			if (format[counter] == 'c')
				ft_putchar(va_arg(va, int));
			else if (format[counter] == 's')
				ft_putstr(va_arg(va, char *));
			else if (format[counter] == 'p') {}
				// unsigned long long kullanılabilir.
			else if (format[counter] == 'i' || format[counter] == 'd')
				ft_putnbr(va_arg(va, int));
			else if (format[counter] == 'u') {}
				// unsigned int yazdır
			else if (format[counter] == 'x') {}
				// hexadeciaml sayı kucuk harfler ile yazdır
			else if (format[counter] == 'X') {}
				// hexadecimal sayı buyuk harfler ile yazdır
			else if (format[counter] == '%')
				write(1, "%", 1);
			
		}
		else
		{
			ft_putchar(format[counter]);
		}
}
