/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:22:56 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/10 13:55:44 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_free(void *content)
// {
// 	free(content);
// }

void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	while (i >= 0)
		free(tab[i--]);
	free(tab);
}
