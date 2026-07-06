/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:07:59 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/05 14:41:08 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_order(char **tab)
{
	int	len;
	int	i;

	len = 0;
	while (tab[len])
		len++;
	i = 0;
	while (tab[len - 1][i])
	{
		if (tab[len - 1][i] != '1' && tab[len - 1][i] != ' ' && tab[len
			- 1][i] != '0')
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

bool	check_data(t_data *data)
{
	if (check_order(data->file.tab) == false)
		exit_failure(data, "Map is not at the end of the file");
	if (check_texture(data->file.tab, "NO") == false
		&& check_texture(data->file.tab, "N") == false)
		exit_failure(data, "Missing or invalid NO texture");
	if (check_texture(data->file.tab, "SO") == false
		&& check_texture(data->file.tab, "S") == false)
		exit_failure(data, "Missing or invalid SO texture");
	if (check_texture(data->file.tab, "WE") == false
		&& check_texture(data->file.tab, "W") == false)
		exit_failure(data, "Missing or invalid WE texture");
	if (check_texture(data->file.tab, "EA") == false
		&& check_texture(data->file.tab, "E") == false)
		exit_failure(data, "Missing or invalid EA texture");
	if (check_colors(data->file.tab, "F") == false)
		exit_failure(data, "Missing or invalid F color");
	if (check_colors(data->file.tab, "C") == false)
		exit_failure(data, "Missing or invalid C color");
	return (true);
}
