/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_enemies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:16:13 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/26 18:38:49 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_ray_data(t_ray *ray, t_enemy *enemy)
{
	ray->ray_dir.x = enemy->sprite->dir.x;
	ray->ray_dir.y = enemy->sprite->dir.y;
	if (ray->ray_dir.x == 0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = fabsf(1 / ray->ray_dir.x);
	if (ray->ray_dir.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = fabsf(1 / ray->ray_dir.y);
	ray->map.x = (int)enemy->sprite->pos.x;
	ray->map.y = (int)enemy->sprite->pos.y;
	ray->hit = 0;
}

static void	init_ray_step(t_ray *ray, t_enemy *enemy)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (enemy->sprite->pos.x - ray->map.x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - enemy->sprite->pos.x)
			* ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (enemy->sprite->pos.y - ray->map.y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - enemy->sprite->pos.y)
			* ray->delta_dist.y;
	}
}

static void	dda_algorithm(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = VERT_HIT;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = HORI_HIT;
		}
		if (data->map[ray->map.y][ray->map.x] == WALL)
			ray->hit = 1;
		else if (data->map[ray->map.y][ray->map.x] == DOOR)
		{
			if (is_door_blocking(data, ray->map.x, ray->map.y))
				ray->hit = 1;
		}
		else if (ray->map.x == (int)data->player.pos.x
			&& ray->map.y == (int)data->player.pos.y)
			break ;
	}
}

bool	can_see_player(t_data *data, t_enemy *enemy)
{
	t_ray	ray;

	init_ray_data(&ray, enemy);
	init_ray_step(&ray, enemy);
	dda_algorithm(data, &ray);
	return (ray.hit == 0);
}
