/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_floor_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:29:45 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/14 15:38:00 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_floor_column(t_data *data, t_ray ray, int x, int wall_draw_end)
{
	int				y;
	int				color;
	t_coord_float	floor;

	y = wall_draw_end;
	ray.pos_z = 0.5 * WIN_HEIGHT;
	while (y < WIN_HEIGHT)
	{
		ray.p = y - WIN_HEIGHT / 2;
		ray.row_distance = ray.pos_z / ray.p;
		floor.x = data->player.pos.x + ray.row_distance * ray.ray_dir.x;
		floor.y = data->player.pos.y + ray.row_distance * ray.ray_dir.y;
		ray.tex_x = (int)(FLOOR_TEX_WIDTH * (floor.x - (int)floor.x))
			% FLOOR_TEX_WIDTH;
		ray.tex_y = (int)(FLOOR_TEX_HEIGHT * (floor.y - (int)floor.y))
			% FLOOR_TEX_HEIGHT;
		color = get_texture_color(&data->texture.floor, ray.tex_x,
				ray.tex_y);
		apply_shadow(ray.row_distance, &color, 'W');
		img_pix_put(&data->frame, x, y, color);
		y++;
	}
}
