/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:14:42 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/22 12:13:46 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;
//
// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

char	*ft_strjoin_free(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			dst[i] = s1[i];
			i++;
		}
	}
	j = 0;
	if (s2)
		while (s2[j])
			dst[i++] = s2[j++];
	dst[i] = '\0';
	free(s1);
	return (dst);
}

// void	ft_bzero(void *s, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*str;
//
// 	i = 0;
// 	str = s;
// 	while (i < n)
// 	{
// 		str[i] = 0;
// 		i++;
// 	}
// }

// void	*ft_calloc(size_t n, size_t size)
// {
// 	void	*ptr;
// 	size_t	len;

// 	if (n && size > (size_t)-1 / n)
// 		return (NULL);
// 	len = n * size;
// 	ptr = (void *)malloc(len);
// 	if (!ptr)
// 		return (NULL);
// 	ft_bzero(ptr, len);
// 	return (ptr);
// }
