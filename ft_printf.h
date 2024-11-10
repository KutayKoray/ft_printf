/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:53:02 by kkoray            #+#    #+#             */
/*   Updated: 2024/11/10 15:31:44 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

#include <stddef.h>

void	ft_putnbr(int n);
void	ft_putchar(char c);
char	*ft_itoa(int n, int base);
int		print_str(char *s);
char	*to_upper(char *str);
char	*ft_uitoa(unsigned long value, int base);
unsigned long		get_length(unsigned long value, int base);
void	reverse(char *buffer, int length);
int		ft_printf(const char *format, ...);
int		print_str_free(char *s);

#endif