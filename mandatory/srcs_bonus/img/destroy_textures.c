/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:48:15 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/04 19:35:54 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	destroy_doors(t_data *data)
{
	if (data->texture.door_closed.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.door_closed.image);
	if (data->texture.door_half_open.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.door_half_open.image);
	if (data->texture.door_open.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.door_open.image);
	if (data->texture.up_door_closed.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.up_door_closed.image);
	if (data->texture.up_door_half_open.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.up_door_half_open.image);
	if (data->texture.up_door_open.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.up_door_open.image);
}

static void	destroy_hud(t_data *data)
{
	if (data->texture.minimap.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.minimap.image);
	if (data->texture.map_frame.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.map_frame.image);
	if (data->texture.map_wall.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.map_wall.image);
	if (data->texture.map_floor.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.map_floor.image);
	if (data->texture.bar.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.bar.image);
	if (data->texture.health_bar.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.health_bar.image);
	if (data->texture.stamina_bar.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.stamina_bar.image);
	if (data->texture.magic_bar.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.magic_bar.image);
	if (data->texture.cursor.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.cursor.image);
	if (data->texture.death_screen.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.death_screen.image);
	if (data->texture.starting_screen_0.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.starting_screen_0.image);
	if (data->texture.starting_screen_1.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.starting_screen_1.image);
}

static void	destroy_room(t_data *data)
{
	if (data->texture.north.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.north.image);
	if (data->texture.south.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.south.image);
	if (data->texture.east.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.east.image);
	if (data->texture.west.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.west.image);
	if (data->texture.up_north.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.up_north.image);
	if (data->texture.up_south.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.up_south.image);
	if (data->texture.up_west.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.up_west.image);
	if (data->texture.up_east.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.up_east.image);
	if (data->texture.floor.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.floor.image);
	if (data->texture.ceiling.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.ceiling.image);
}

void	destroy_textures(t_data *data)
{
	destroy_doors(data);
	destroy_hud(data);
	destroy_room(data);
}
