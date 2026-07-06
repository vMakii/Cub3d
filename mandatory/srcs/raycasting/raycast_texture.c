/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:04:32 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/05 14:12:15 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// texPos starts at offset of the top of the wall (how many pixels of texture
// (with the texStep ratio) above the center of the screen)
void	get_texture_column(t_data *data)
{
	data->ray.tex_x = (int)(data->ray.wall_x * (float)WALL_TEX_WIDTH);
	if ((data->ray.side == VERT_HIT && data->ray.ray_dir.x < 0)
		|| (data->ray.side == HORI_HIT && data->ray.ray_dir.y > 0))
		data->ray.tex_x = (WALL_TEX_WIDTH - 1) - data->ray.tex_x;
	data->ray.tex_step = 1.0 * WALL_TEX_HEIGHT / data->ray.line_height;
	data->ray.tex_pos = (data->ray.draw_start - WIN_HEIGHT / 2
			+ data->ray.line_height / 2) * data->ray.tex_step;
}

t_image	find_correct_texture(t_data *data)
{
	t_image	texture;

	if (data->ray.side == VERT_HIT && data->ray.ray_dir.x < 0)
		texture = data->sprite.west;
	else if (data->ray.side == VERT_HIT && data->ray.ray_dir.x > 0)
		texture = data->sprite.east;
	else if (data->ray.side == HORI_HIT && data->ray.ray_dir.y < 0)
		texture = data->sprite.north;
	else
		texture = data->sprite.south;
	return (texture);
}

void	draw_wall_texture(t_data *data, int x, t_image texture)
{
	int	y;
	int	color;

	y = data->ray.draw_start;
	while (y < data->ray.draw_end)
	{
		data->ray.tex_y = (int)data->ray.tex_pos % WALL_TEX_HEIGHT;
		data->ray.tex_pos += data->ray.tex_step;
		color = get_texture_color(&texture, data->ray.tex_x, data->ray.tex_y,
				WALL);
		img_pix_put(&data->frame, x, y, color);
		y++;
	}
}

void	draw_sky_floor(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->ray.draw_start)
	{
		if (y >= 0 && y < WIN_HEIGHT && x >= 0 && x < WIN_WIDTH)
			img_pix_put(&data->frame, x, y, data->texture.ceiling_color);
		y++;
	}
	y = data->ray.draw_end;
	while (y < WIN_HEIGHT)
	{
		if (y >= 0 && y < WIN_HEIGHT && x >= 0 && x < WIN_WIDTH)
			img_pix_put(&data->frame, x, y, data->texture.floor_color);
		y++;
	}
}

void	draw_texture(t_data *data, int x)
{
	t_image	texture;

	get_texture_column(data);
	texture = find_correct_texture(data);
	draw_wall_texture(data, x, texture);
	draw_sky_floor(data, x);
}
