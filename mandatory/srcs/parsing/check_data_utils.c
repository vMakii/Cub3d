/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:33:39 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/05 14:45:33 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_texture(char **tab, char *id)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (tab[i] && ft_strlen(tab[i]) >= 2)
	{
		if (!ft_strncmp(tab[i], id, 2) && tab[i][2] == ' ')
		{
			if (ft_count_word(tab[i], ' ') != 2)
				return (false);
			count++;
		}
		else if (!ft_strncmp(tab[i], id, 1) && tab[i][1] == ' ')
		{
			if (ft_count_word(tab[i], ' ') != 2)
				return (false);
			count++;
		}
		i++;
	}
	if (count == 1)
		return (true);
	return (false);
}

static int	check_colors_3(char *str, int *j)
{
	int	len;

	while (str[*j] && str[*j] == '0')
		(*j)++;
	len = *j;
	while (str[len] && ft_isdigit(str[len]))
		len++;
	if (len - *j > 3)
		return (0);
	*j = len;
	return (1);
}

static int	check_colors_2(char *str)
{
	int	j;
	int	count;

	if (!str || ft_strlen(str) < 2)
		return (0);
	count = 0;
	j = 1;
	while (str[j])
	{
		if (j == (int)ft_strlen(str) - 1)
			if (!ft_isdigit(str[j]))
				return (0);
		if (str[j] != ' ' && !ft_isdigit(str[j]) && str[j] != ',')
			return (0);
		if (ft_isdigit(str[j]) && (j == 0 || !ft_isdigit(str[j - 1])))
		{
			count++;
			if (!check_colors_3(str, &j))
				return (0);
		}
		else
			j++;
	}
	return (count);
}

bool	check_colors(char **tab, char *id)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (tab[i] && ft_strlen(tab[i]) >= 2)
	{
		if (!ft_strncmp(tab[i], id, 1) && tab[i][1] == ' ')
		{
			if (check_colors_2(tab[i]) != 3)
				return (false);
			count++;
		}
		i++;
	}
	if (count == 1)
		return (true);
	return (false);
}
