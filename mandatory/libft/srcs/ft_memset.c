/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:26:08 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/13 11:59:38 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)ptr;
	i = 0;
	while (i < n)
	{
		str[i] = value;
		i++;
	}
	return (ptr);
}
