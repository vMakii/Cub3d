/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:04:32 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/19 20:40:31 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// texPos starts at offset of the top of the wall (how many pixels of texture 
// (with the texStep ratio) above the center of the screen)
void	get_texture_column(t_ray *ray, char c)
{
	int	tex_width;
	int	tex_height;

	if (c == 'D')
	{
		tex_width = DOOR_TEX_WIDTH;
		tex_height = DOOR_TEX_HEIGHT;
	}
	else
	{
		tex_width = WALL_TEX_WIDTH;
		tex_height = WALL_TEX_HEIGHT;
	}
	ray->tex_x = (int)(ray->wall_x * (float)tex_width);
	if ((ray->side == VERT_HIT && ray->ray_dir.x < 0)
		|| (ray->side == HORI_HIT && ray->ray_dir.y > 0))
		ray->tex_x = (tex_width - 1) - ray->tex_x;
	ray->tex_step = 1.0 * tex_height / ray->line_height;
	ray->tex_pos = (ray->draw_start - WIN_HEIGHT / 2
			+ ray->line_height / 2) * ray->tex_step;
}

static t_image	find_correct_texture(t_data *data, t_ray *ray)
{
	t_image	texture;

	if (ray->side == VERT_HIT && ray->ray_dir.x < 0)
		texture = data->texture.west;
	else if (ray->side == VERT_HIT && ray->ray_dir.x > 0)
		texture = data->texture.east;
	else if (ray->side == HORI_HIT && ray->ray_dir.y < 0)
		texture = data->texture.north;
	else
		texture = data->texture.south;
	return (texture);
}

void	draw_wall_texture(t_data *data, t_ray *ray, int x, t_image texture)
{
	int		y;
	int		color;

	color = 0;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos % WALL_TEX_HEIGHT;
		ray->tex_pos += ray->tex_step;
		color = get_texture_color(&texture, ray->tex_x, ray->tex_y);
		apply_shadow(ray->perp_wall_dist, &color, 'W');
		img_pix_put(&data->frame, x, y, color);
		y++;
	}
}

void	draw_wall(t_data *data, t_ray *ray, int x)
{
	t_image	texture;

	get_texture_column(ray, 'W');
	texture = find_correct_texture(data, ray);
	draw_wall_texture(data, ray, x, texture);
}
