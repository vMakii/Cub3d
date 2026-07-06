/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:15:02 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/29 10:53:54 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_hex(unsigned int n, char c)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_print_hex(n / 16, c);
		len += ft_print_hex(n % 16, c);
	}
	else
	{
		if (n < 10)
			len += ft_putchar(n + '0');
		else
		{
			if (c == 'x')
				len += ft_putchar(n - 10 + 'a');
			if (c == 'X')
				len += ft_putchar(n - 10 + 'A');
		}
	}
	return (len);
}

int	ft_puthexa(unsigned int n, char c)
{
	int	len;

	len = 0;
	len += ft_print_hex(n, c);
	return (len);
}
