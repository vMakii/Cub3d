/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:35:06 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/20 13:30:28 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	len;

	if (n && size > (size_t)-1 / n)
		return (NULL);
	len = n * size;
	ptr = (void *)malloc(len);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, len);
	return (ptr);
}
