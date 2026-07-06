/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:59:00 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/14 11:37:23 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	get_color_2(int *texture, char *str)
{
	int	i;
	int	j;
	int	color[3];

	i = 0;
	j = 1;
	while (str[j] && i < 3)
	{
		if (str[j] != ' ' && !ft_isdigit(str[j]) && str[j] != ',')
			return (false);
		if (ft_isdigit(str[j]) && !ft_isdigit(str[j - 1]))
		{
			color[i] = ft_atoi(&str[j]);
			i++;
		}
		j++;
	}
	if (color[0] > 255 || color[1] > 255 || color[2] > 255)
		return (false);
	*texture = rgb_to_int(color[0], color[1], color[2]);
	return (true);
}

bool	get_color(t_data *data, char *id)
{
	int	i;

	i = 0;
	while (data->file.tab[i])
	{
		if (!ft_strncmp(data->file.tab[i], "F", 1) && ft_strncmp(id, "F", 1))
			if (get_color_2(&data->file.floor_color,
					data->file.tab[i]) == true)
				return (true);
		if (!ft_strncmp(data->file.tab[i], "C", 1) && ft_strncmp(id, "C", 1))
			if (get_color_2(&data->file.ceiling_color,
					data->file.tab[i]) == true)
				return (true);
		i++;
	}
	return (false);
}

static bool	get_texture_2(t_data *data, char **texture, char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
	{
		*texture = ft_strdup(&str[i]);
		gc_add_malloc(*texture, &data->gc_list);
		if (access(*texture, F_OK | R_OK) == -1)
			exit_failure(data, *texture);
		if (check_filename(*texture, ".xpm") == false)
			exit_failure(data, *texture);
	}
	if (*texture)
		return (true);
	return (false);
}

bool	get_textures(t_data *data)
{
	int		i;

	i = 0;
	while (data->file.tab[i])
	{
		if (!ft_strncmp(data->file.tab[i], "NO", 2))
			if (get_texture_2(data, &data->file.north_texture,
					data->file.tab[i]) == false)
				return (false);
		if (!ft_strncmp(data->file.tab[i], "SO", 2))
			if (get_texture_2(data, &data->file.south_texture,
					data->file.tab[i]) == false)
				return (false);
		if (!ft_strncmp(data->file.tab[i], "WE", 2))
			if (get_texture_2(data, &data->file.west_texture,
					data->file.tab[i]) == false)
				return (false);
		if (!ft_strncmp(data->file.tab[i], "EA", 2))
			if (get_texture_2(data, &data->file.east_texture,
					data->file.tab[i]) == false)
				return (false);
		i++;
	}
	return (true);
}

bool	get_data(t_data *data)
{
	if (get_textures(data) == false)
		return (false);
	if (!data->file.north_texture || !data->file.south_texture
		|| !data->file.west_texture || !data->file.east_texture)
		return (false);
	if (get_color(data, "C") == false)
		return (false);
	if (get_color(data, "F") == false)
		return (false);
	return (true);
}
