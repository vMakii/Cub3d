/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:44:33 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/03 10:51:15 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	render_frame(t_data *data)
{
	if (data->mlx.ptr == NULL)
		return (1);
	data->frame.image = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	data->frame.data = mlx_get_data_addr((void *)data->frame.image,
			&data->frame.bpp, &data->frame.size_line, &data->frame.endian);
	if (data->player.is_hit)
		upscale_img(data, &data->texture.hit, 0, 0);
	else if (data->player.hp == 0)
		upscale_img(data, &data->texture.death_screen, 0, 0);
	else
	{
		raycasting(data);
		render_sprites(data);
		render_effects(data);
		render_player(data);
		render_hud(data);
	}
	mlx_do_sync(data->mlx.ptr);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->frame.image, 0,
		0);
	print_fps(data);
	mlx_destroy_image(data->mlx.ptr, data->frame.image);
	return (0);
}

int	loop(t_data *data)
{
	fps_counter(data);
	player_move(data);
	update_doors(data);
	update_enemies(data);
	render_frame(data);
	return (0);
}
