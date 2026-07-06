/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:34:04 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/29 10:53:33 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_args(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putvoid(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	args;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_args(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
