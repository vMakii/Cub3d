/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 21:45:38 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/22 10:18:15 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	render_hp_2(t_data *data, int draw_end, int dest_x, int dest_y)
{
	int	x;
	int	y;
	int	color;
	int	px_y;
	int	px_x;

	y = -1;
	while (++y < data->texture.health_bar.height)
	{
		x = -1;
		while (++x < draw_end)
		{
			color = get_texture_color(&data->texture.health_bar, x, y);
			px_y = -1;
			while (++px_y < UPSCALING)
			{
				px_x = -1;
				while (++px_x < UPSCALING)
				{
					img_pix_put(&data->frame, dest_x + x * UPSCALING + px_x,
						dest_y + y * UPSCALING + px_y, color);
				}
			}
		}
	}
}

void	render_hp(t_data *data)
{
	int	draw_end;
	int	dest_x;
	int	dest_y;

	dest_x = WIN_WIDTH / 2 - data->texture.health_bar.width * UPSCALING / 2;
	dest_y = WIN_HEIGHT - (data->texture.health_bar.height + 1) * UPSCALING
		- 20;
	draw_end = data->texture.health_bar.width * data->player.hp / 100;
	render_hp_2(data, draw_end, dest_x, dest_y);
}

void	render_health_bar(t_data *data)
{
	upscale_img(data, &data->texture.bar, WIN_WIDTH / 2
		- data->texture.bar.width * UPSCALING / 2, WIN_HEIGHT
		- data->texture.bar.height * UPSCALING - 20);
	render_hp(data);
}
