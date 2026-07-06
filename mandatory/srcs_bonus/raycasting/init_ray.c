/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:58:04 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/14 14:25:06 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_ray_data(t_data *data, t_ray *ray, int x)
{
	ray->camera_x = 2.0 * x / (float)WIN_WIDTH - 1.0;
	ray->ray_dir.x = data->player.dir.x + data->player.plane.x
		* ray->camera_x;
	ray->ray_dir.y = data->player.dir.y + data->player.plane.y
		* ray->camera_x;
	if (ray->ray_dir.x == 0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = fabsf(1 / ray->ray_dir.x);
	if (ray->ray_dir.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = fabsf(1 / ray->ray_dir.y);
	ray->map.x = (int)data->player.pos.x;
	ray->map.y = (int)data->player.pos.y;
	ray->hit = 0;
}

static void	init_ray_step(t_data *data, t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (data->player.pos.x - ray->map.x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - data->player.pos.x)
			* ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (data->player.pos.y - ray->map.y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - data->player.pos.y)
			* ray->delta_dist.y;
	}
}

void	init_ray(t_data *data, t_ray *ray, int x)
{
	init_ray_data(data, ray, x);
	init_ray_step(data, ray);
}
