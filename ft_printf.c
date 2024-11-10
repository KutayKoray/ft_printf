/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:52:30 by kkoray            #+#    #+#             */
/*   Updated: 2024/11/10 15:29:01 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>

int	print_char(int c)
{
	ft_putchar(c);
	return (1);
}

int	v_format(va_list va, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += print_char(va_arg(va, int));
	else if (format == 's')
		len += print_str(va_arg(va, char *));
	else if (format == 'd' || format == 'i')
		len += print_str_free(ft_itoa(va_arg(va, int), 10));
	else if (format == 'u')
		len += print_str_free(ft_uitoa(va_arg(va, unsigned int), 10));
	else if (format == 'x')
		len += print_str_free(ft_uitoa(va_arg(va, unsigned int), 16));
	else if (format == 'X')
		len += print_str_free(to_upper(ft_uitoa(va_arg(va, unsigned int), 16)));
	else if (format == 'p')
	{
		len += print_str("0x");
		len += print_str_free(ft_uitoa(va_arg(va, unsigned long), 16));
	}
	else if (format == '%')
		len += print_char('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	va;
	size_t	len;

	len = 0;
	va_start(va, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += v_format(va, *format);
		}
		else
			len += print_char(*format);
		format++;
	}
	va_end(va);
	return (len);
}

// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	// ft_printf("%d", INT_MIN);

// 	// int a = -42;

// 	// int len = ft_printf("%i\n", a);
// 	// int len2 = printf("%i\n", a);
// 	// printf("len: %d\n", len);
// 	// printf("len2: %d\n", len2);

// 	ft_printf(" %p \n", -1);
//     ft_printf(" %p \n", 1);
//     ft_printf(" %p \n", 15);
//     ft_printf(" %p \n", 16);
//     ft_printf(" %p \n", 17);
//     ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
//     ft_printf(" %p %p \n", INT_MIN, INT_MAX);
//     ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
//     ft_printf(" %p %p \n", 0, 0);

// 	printf("--------------------------------\n");

// 	printf(" %p \n", -1);
//     printf(" %p \n", 1);
//     printf(" %p \n", 15);
//     printf(" %p \n", 16);
//     printf(" %p \n", 17);
//     printf(" %p %p \n", LONG_MIN, LONG_MAX);
//     printf(" %p %p \n", INT_MIN, INT_MAX);
//     printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
//     printf(" %p %p \n", 0, 0);

// 	/*	bu senaryoda farklılık var.
// 	int len = ft_printf("%\n");
// 	int len2 = printf("%\n");
// 	printf("len: %d\n", len);
// 	printf("len2: %d\n", len2);
// 	*/
// }