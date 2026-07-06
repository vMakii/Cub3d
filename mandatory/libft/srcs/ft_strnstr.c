/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:57:30 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/12 15:38:17 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (!to_find[0])
		return ((char *)str);
	if (!n)
		return (0);
	i = 0;
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] && str[i + j] == to_find[j] && i + j < n)
			j++;
		if (!to_find[j])
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
