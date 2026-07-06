/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_doors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 20:59:36 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/21 15:26:52 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	toggle_door_at_position(t_data *data, int map_x, int map_y)
{
	int		i;

	i = 0;
	while (i < data->doors.count)
	{
		if (data->doors.doors[i].pos.x == map_x
			&& data->doors.doors[i].pos.y == map_y)
		{
			data->doors.doors[i].is_open = !data->doors.doors[i].is_open;
			return ;
		}
		i++;
	}
}

void	interact_with_door(t_data *data)
{
	if (data->player.central_ray_distance > INTERACTION_DISTANCE)
		return ;
	if (data->map[data->player.central_ray_map_y]
		[data->player.central_ray_map_x] == 'D')
	{
		toggle_door_at_position(data, data->player.central_ray_map_x,
			data->player.central_ray_map_y);
	}
}

bool	is_door_blocking(t_data *data, int map_x, int map_y)
{
	int		i;
	t_door	door;

	if (data->map[map_y][map_x] != DOOR)
		return (false);
	i = 0;
	while (i < data->doors.count)
	{
		door = data->doors.doors[i];
		if (door.pos.x == map_x && door.pos.y == map_y)
			return (door.open_amount < 0.7f);
		i++;
	}
	return (true);
}
