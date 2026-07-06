/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:39:14 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/22 14:39:23 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabcpy(char **src)
{
	int		i;
	char	**cpy;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	cpy = malloc(sizeof(char *) * (i + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cpy[i] = ft_strdup(src[i]);
		if (!cpy[i])
		{
			ft_freetab(cpy);
			return (NULL);
		}
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
