/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_ceiling_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:30:18 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/15 20:06:16 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// ray.pos_z factor: 0.5 for simple wall or 1.5 for double wall ceiling
void	draw_ceiling_column(t_data *data, t_ray ray, int x, int ceiling_end)
{
	int				y;
	int				color;
	t_coord_float	ceiling;

	y = 0;
	ray.pos_z = 1.5 * WIN_HEIGHT;
	while (y < ceiling_end)
	{
		ray.p = WIN_HEIGHT / 2 - y;
		ray.row_distance = ray.pos_z / ray.p;
		ceiling.x = data->player.pos.x + ray.row_distance * ray.ray_dir.x;
		ceiling.y = data->player.pos.y + ray.row_distance * ray.ray_dir.y;
		ray.tex_x = (int)(CEILING_TEX_WIDTH * (ceiling.x - (int)ceiling.x))
			% CEILING_TEX_WIDTH;
		ray.tex_y = (int)(CEILING_TEX_HEIGHT * (ceiling.y - (int)ceiling.y))
			% CEILING_TEX_HEIGHT;
		color = get_texture_color(&data->texture.ceiling, ray.tex_x,
				ray.tex_y);
		apply_shadow(ray.row_distance, &color, 'W');
		img_pix_put(&data->frame, x, y, color);
		y++;
	}
}
