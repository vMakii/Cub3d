/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_nl_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:18:25 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/02 14:29:03 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	ismap(char *str, int i)
{
	while (str[i] && str[i] != '\n')
	{
		if (is_valid_map_char(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

bool	check_map_nl(char *str)
{
	int	i;

	i = 0;
	while (!ismap(str, i))
	{
		while (str[i] && str[i] != '\n')
			i++;
		while (str[i] == '\n')
			i++;
	}
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (false);
		i++;
	}
	return (true);
}
