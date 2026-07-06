/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:59:00 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/05 14:47:09 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	get_color_2(int *texture, char *str)
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

static bool	get_color(t_data *data, char *id)
{
	int	i;

	i = 0;
	while (data->file.tab[i])
	{
		if (!ft_strncmp(data->file.tab[i], "F", 1) && ft_strncmp(id, "F", 1))
			if (get_color_2(&data->texture.floor_color,
					data->file.tab[i]) == true)
				return (true);
		if (!ft_strncmp(data->file.tab[i], "C", 1) && ft_strncmp(id, "C", 1))
			if (get_color_2(&data->texture.ceiling_color,
					data->file.tab[i]) == true)
				return (true);
		i++;
	}
	return (false);
}

static bool	get_texture_2(t_data *data, char **texture, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
	{
		*texture = ft_strdup(&str[i]);
		gc_add_malloc(*texture, &data->gc_list);
		if (open(*texture, O_RDONLY) == -1)
			exit_failure(data, *texture);
		if (check_filename(*texture, ".xpm") == false)
			exit_failure(data, *texture);
	}
	if (*texture)
		return (true);
	return (false);
}

static bool	get_textures(t_data *data, int i)
{
	if ((!ft_strncmp(data->file.tab[i], "NO", 2) && data->file.tab[i][2] == ' ')
		|| (!ft_strncmp(data->file.tab[i], "N", 1)
		&& data->file.tab[i][1] == ' '))
		if (get_texture_2(data, &data->texture.north_texture,
				data->file.tab[i]) == false)
			return (false);
	if ((!ft_strncmp(data->file.tab[i], "SO", 2) && data->file.tab[i][2] == ' ')
		|| (!ft_strncmp(data->file.tab[i], "S", 1)
		&& data->file.tab[i][1] == ' '))
		if (get_texture_2(data, &data->texture.south_texture,
				data->file.tab[i]) == false)
			return (false);
	if ((!ft_strncmp(data->file.tab[i], "WE", 2) && data->file.tab[i][2] == ' ')
		|| (!ft_strncmp(data->file.tab[i], "W", 1)
		&& data->file.tab[i][1] == ' '))
		if (get_texture_2(data, &data->texture.west_texture,
				data->file.tab[i]) == false)
			return (false);
	if ((!ft_strncmp(data->file.tab[i], "EA", 2) && data->file.tab[i][2] == ' ')
		|| (!ft_strncmp(data->file.tab[i], "E", 1)
		&& data->file.tab[i][1] == ' '))
		if (get_texture_2(data, &data->texture.east_texture,
				data->file.tab[i]) == false)
			return (false);
	return (true);
}

bool	get_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->file.tab[i])
	{
		if (get_textures(data, i) == false)
			return (false);
		i++;
	}
	if (!data->texture.north_texture || !data->texture.south_texture
		|| !data->texture.west_texture || !data->texture.east_texture)
		return (false);
	if (get_color(data, "C") == false)
		return (false);
	if (get_color(data, "F") == false)
		return (false);
	return (true);
}
