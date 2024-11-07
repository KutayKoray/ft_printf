/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoray <kkoray@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:18:35 by kkoray            #+#    #+#             */
/*   Updated: 2024/11/07 17:28:08 by kkoray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int n)
{
    if(n == -2147483648)
        write(1, "-2147483648", 11);

    else if(n < 0)
    {
        write(1, "-", 1);
        n *= -1;
        ft_putnbr(n);
    }
    else
    {
        if(n > 9)
        {
            ft_putnbr(n / 10);
            ft_putnbr(n % 10);
        }
        else
        {
            n += '0';
            write(1, &n, 1);
        }
    }
}

void    ft_putstr(char *s)
{
    int i;

    i = 0;
	if (!s)
		s = "(null)";
    while(s[i++])
        write(1, &s[i], 1);
}
