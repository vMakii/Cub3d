/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:31:25 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/12 15:32:56 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	ldst;
	size_t	lsrc;

	i = 0;
	if (!dst && n == 0)
		return (ft_strlen(src));
	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (!n || n <= ldst)
		return (n + lsrc);
	while (src[i] && i + ldst < n - 1)
	{
		dst[ldst + i] = src[i];
		i++;
	}
	dst[ldst + i] = '\0';
	return (ldst + lsrc);
}
