/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_doors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:09:14 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/05 14:24:42 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_door_texture_index(t_data *data, int map_x, int map_y)
{
	int		i;
	t_door	*door;

	i = 0;
	while (i < data->doors.count)
	{
		door = &data->doors.doors[i];
		if (door->pos.x == map_x && door->pos.y == map_y)
			return (door->sprite_index);
		i++;
	}
	return (0);
}

bool	should_ray_pass_through_door(t_data *data, t_ray *ray, int x)
{
	int		door_texture_index;
	int		color;
	t_image	texture;

	door_texture_index = get_door_texture_index(data, ray->map.x, ray->map.y);
	perp_distance_to_wall(data, ray);
	update_central_ray(data, ray, x);
	get_wall_column(data, ray);
	get_texture_column(ray, 'D');
	if (door_texture_index == 0)
		texture = data->texture.door_closed;
	else if (door_texture_index == 1)
		texture = data->texture.door_half_open;
	else
		texture = data->texture.door_open;
	color = get_texture_color(&texture, ray->tex_x, DOOR_TEX_HEIGHT / 2);
	if (is_pixel_transparent(color))
		return (true);
	else
	{
		draw_wall_texture(data, ray, x, texture);
		draw_double_wall(data, ray, x);
	}
	return (false);
}
