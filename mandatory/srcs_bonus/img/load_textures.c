/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:25:26 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/02 11:07:26 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	load_doors(t_data *data)
{
	load_img(data, &data->texture.door_closed,
		"./assets/xpm/doors/door_closed.xpm");
	load_img(data, &data->texture.door_half_open,
		"./assets/xpm/doors/door_half.xpm");
	load_img(data, &data->texture.door_open,
		"./assets/xpm/doors/door_open.xpm");
	load_img(data, &data->texture.up_door_closed,
		"./assets/xpm/doors/door_closed.xpm");
	load_img(data, &data->texture.up_door_half_open,
		"./assets/xpm/doors/door_half.xpm");
	load_img(data, &data->texture.up_door_open,
		"./assets/xpm/doors/door_open.xpm");
}

static void	load_hud(t_data *data)
{
	load_img(data, &data->texture.minimap, "./assets/xpm/hud/minimap.xpm");
	load_img(data, &data->texture.map_frame,
		"./assets/xpm/hud/minimap_frame.xpm");
	load_img(data, &data->texture.map_wall, "./assets/xpm/hud/wall.xpm");
	load_img(data, &data->texture.map_floor, "./assets/xpm/hud/floor.xpm");
	load_img(data, &data->texture.bar, "./assets/xpm/hud/bar.xpm");
	load_img(data, &data->texture.health_bar,
		"./assets/xpm/hud/health_bar.xpm");
	load_img(data, &data->texture.stamina_bar,
		"./assets/xpm/hud/stamina_bar.xpm");
	load_img(data, &data->texture.magic_bar, "./assets/xpm/hud/magic_bar.xpm");
	load_img(data, &data->texture.cursor, "./assets/xpm/hud/cursor.xpm");
	load_img(data, &data->texture.death_screen,
		"./assets/xpm/screen/death_screen.xpm");
}

static void	load_room(t_data *data)
{
	load_img(data, &data->texture.north, "./assets/xpm/wall/down/windows.xpm");
	load_img(data, &data->texture.south, "./assets/xpm/wall/down/windows.xpm");
	load_img(data, &data->texture.west, "./assets/xpm/wall/down/normal.xpm");
	load_img(data, &data->texture.east, "./assets/xpm/wall/down/normal.xpm");
	load_img(data, &data->texture.up_north, "./assets/xpm/wall/up/windows.xpm");
	load_img(data, &data->texture.up_south, "./assets/xpm/wall/up/windows.xpm");
	load_img(data, &data->texture.up_west, "./assets/xpm/wall/up/normal.xpm");
	load_img(data, &data->texture.up_east, "./assets/xpm/wall/up/normal.xpm");
	load_img(data, &data->texture.floor, "./assets/xpm/floor/floor.xpm");
	load_img(data, &data->texture.ceiling, "./assets/xpm/ceiling/ceiling.xpm");
}

void	load_textures(t_data *data)
{
	load_doors(data);
	load_hud(data);
	load_room(data);
}
