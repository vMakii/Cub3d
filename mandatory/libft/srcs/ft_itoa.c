/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:45:59 by mivogel           #+#    #+#             */
/*   Updated: 2025/01/16 14:04:01 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	long	nb;
	int		len;

	nb = (long)nbr;
	len = ft_get_size(nb);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	str[len--] = '\0';
	while (nb)
	{
		str[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
