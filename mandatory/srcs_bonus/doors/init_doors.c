/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 00:00:00 by mivogel           #+#    #+#             */
/*   Updated: 2025/08/19 21:11:28 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	update_doors_capacity(t_data *data)
{
	int		i;
	int		new_capacity;
	t_door	*new_doors;

	if (data->doors.count >= data->doors.capacity)
	{
		if (data->doors.capacity == 0)
			new_capacity = 10;
		else
			new_capacity = data->doors.capacity * 2;
		new_doors = gc_malloc(sizeof(t_door) * new_capacity, &data->gc_list);
		if (data->doors.doors)
		{
			i = 0;
			while (i < data->doors.count)
			{
				new_doors[i] = data->doors.doors[i];
				i++;
			}
		}
		data->doors.doors = new_doors;
		data->doors.capacity = new_capacity;
	}
}

static void	add_door(t_data *data, int x, int y)
{
	t_door	*door;

	update_doors_capacity(data);
	door = &data->doors.doors[data->doors.count];
	door->pos.x = x;
	door->pos.y = y;
	door->is_open = false;
	door->open_amount = 0.0f;
	door->open_speed = 0.05f;
	door->sprite_index = 0;
	data->doors.count++;
}

void	get_doors_from_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == DOOR)
				add_door(data, x, y);
			x++;
		}
		y++;
	}
}
