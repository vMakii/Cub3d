/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_double_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:00:49 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/18 19:22:39 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_column(t_data *data, t_ray *ray, t_image texture, int x)
{
	int	color;
	int	y;

	y = ray->upper_draw_start;
	if (ray->upper_draw_end > ray->upper_draw_start
		&& ray->upper_draw_start >= 0)
	{
		ray->upper_step = 1.0 * WALL_TEX_HEIGHT / ray->upper_wall_height;
		ray->skip_pixels = ray->upper_draw_start
			- ray->original_upper_draw_start;
		ray->upper_tex_pos = ray->skip_pixels * ray->upper_step;
		while (y < ray->upper_draw_end)
		{
			if (y >= 0 && y < WIN_HEIGHT && x >= 0 && x < WIN_WIDTH)
			{
				ray->tex_y = (int)ray->upper_tex_pos & (WALL_TEX_HEIGHT - 1);
				ray->upper_tex_pos += ray->upper_step;
				color = get_texture_color(&texture, ray->tex_x, ray->tex_y);
				apply_shadow(ray->perp_wall_dist, &color, 'W');
				img_pix_put(&data->frame, x, y, color);
			}
			y++;
		}
		ray->draw_start = ray->upper_draw_start;
	}
}

static void	find_correct_texture_double_wall(t_data *data, t_ray *ray,
	t_image *texture)
{
	int		door_texture_index;

	if (data->map[ray->map.y][ray->map.x] == DOOR)
	{
		door_texture_index = get_door_texture_index(data, ray->map.x,
				ray->map.y);
		if (door_texture_index == 0)
			*texture = data->texture.up_door_closed;
		else if (door_texture_index == 1)
			*texture = data->texture.up_door_half_open;
		else
			*texture = data->texture.up_door_open;
	}
	else
	{
		if (ray->side == VERT_HIT && ray->ray_dir.x < 0)
			*texture = data->texture.up_west;
		else if (ray->side == VERT_HIT && ray->ray_dir.x > 0)
			*texture = data->texture.up_east;
		else if (ray->side == HORI_HIT && ray->ray_dir.y < 0)
			*texture = data->texture.up_north;
		else
			*texture = data->texture.up_south;
	}
}

void	draw_double_wall(t_data *data, t_ray *ray, int x)
{
	t_image	texture;

	find_correct_texture_double_wall(data, ray, &texture);
	ray->upper_wall_height = ray->line_height;
	ray->upper_draw_start = ray->draw_start - ray->upper_wall_height;
	ray->upper_draw_end = ray->draw_start;
	ray->original_upper_draw_start = ray->upper_draw_start;
	if (ray->upper_draw_start < 0)
		ray->upper_draw_start = 0;
	if (ray->upper_draw_end >= WIN_HEIGHT)
		ray->upper_draw_end = WIN_HEIGHT - 1;
	draw_column(data, ray, texture, x);
}
