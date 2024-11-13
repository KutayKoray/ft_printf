/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:53:02 by kkoray            #+#    #+#             */
/*   Updated: 2024/11/13 17:02:26 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

void	ft_putnbr(int n);
void	ft_putchar(char c);
char	*ft_itoa(int n, int base);
int		print_str(char *s);
char	*to_upper(char *str);
char	*ft_uitoa(unsigned long value, int base);
void	reverse(char *buffer, unsigned long length);
int		ft_printf(const char *format, ...);
int		print_str_free(char *s);

#endif