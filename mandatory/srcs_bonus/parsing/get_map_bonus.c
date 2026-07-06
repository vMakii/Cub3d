/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:14:30 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/21 12:07:58 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	give_player_direction(t_data *data, char c)
{
	if (c == 'N')
	{
		data->player.angle = 3 * M_PI_2 ;
		data->player.dir.x = cos(data->player.angle);
		data->player.dir.y = sin(data->player.angle);
	}
	else if (c == 'S')
	{
		data->player.angle = M_PI_2;
		data->player.dir.x = cos(data->player.angle);
		data->player.dir.y = sin(data->player.angle);
	}
	else if (c == 'W')
	{
		data->player.angle = M_PI + 0.001f;
		data->player.dir.x = cos(data->player.angle);
		data->player.dir.y = sin(data->player.angle);
	}
	else if (c == 'E')
	{
		data->player.angle = 0.001f;
		data->player.dir.x = cos(data->player.angle);
		data->player.dir.y = sin(data->player.angle);
	}
}

void	get_player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				data->player.pos.x = j + 0.5;
				data->player.pos.y = i + 0.5;
				give_player_direction(data, data->map[i][j]);
				data->player.plane.x = -data->player.dir.y * 0.66f;
				data->player.plane.y = data->player.dir.x * 0.66f;
			}
			j++;
		}
		i++;
	}
}

bool	get_map(t_data *data)
{
	int	i;
	int	len;

	len = 6;
	while (data->file.tab[len])
		len++;
	len -= 5;
	data->map = gc_malloc(len * sizeof(char *), &data->gc_list);
	if (!data->map)
		return (false);
	i = 6;
	while (data->file.tab[i])
	{
		data->map[i - 6] = ft_strdup(data->file.tab[i]);
		if (!data->map[i - 6])
			exit_failure(data, "Map allocation failed");
		gc_add_malloc(data->map[i - 6], &data->gc_list);
		i++;
	}
	data->map[i - 6] = NULL;
	get_player_position(data);
	get_doors_from_map(data);
	get_sprites_from_map(data);
	return (true);
}
