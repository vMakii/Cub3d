/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:58:04 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/15 21:51:14 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray_data(t_data *data, int x)
{
	data->ray.camera_x = 2.0 * x / (float)WIN_WIDTH - 1.0;
	data->ray.ray_dir.x = data->player.dir.x + data->player.plane.x
		* data->ray.camera_x;
	data->ray.ray_dir.y = data->player.dir.y + data->player.plane.y
		* data->ray.camera_x;
	if (data->ray.ray_dir.x == 0)
		data->ray.delta_dist.x = 1e30;
	else
		data->ray.delta_dist.x = fabsf(1 / data->ray.ray_dir.x);
	if (data->ray.ray_dir.y == 0)
		data->ray.delta_dist.y = 1e30;
	else
		data->ray.delta_dist.y = fabsf(1 / data->ray.ray_dir.y);
	data->ray.map.x = (int)data->player.pos.x;
	data->ray.map.y = (int)data->player.pos.y;
}

static void	init_ray_step(t_data *data)
{
	if (data->ray.ray_dir.x < 0)
	{
		data->ray.step.x = -1;
		data->ray.side_dist.x = (data->player.pos.x - data->ray.map.x)
			* data->ray.delta_dist.x;
	}
	else
	{
		data->ray.step.x = 1;
		data->ray.side_dist.x = (data->ray.map.x + 1.0 - data->player.pos.x)
			* data->ray.delta_dist.x;
	}
	if (data->ray.ray_dir.y < 0)
	{
		data->ray.step.y = -1;
		data->ray.side_dist.y = (data->player.pos.y - data->ray.map.y)
			* data->ray.delta_dist.y;
	}
	else
	{
		data->ray.step.y = 1;
		data->ray.side_dist.y = (data->ray.map.y + 1.0 - data->player.pos.y)
			* data->ray.delta_dist.y;
	}
}

void	init_ray(t_data *data, int x)
{
	init_ray_data(data, x);
	init_ray_step(data);
}
