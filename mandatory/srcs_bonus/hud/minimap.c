/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:51:44 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/02 11:13:20 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// inside size frame = 36, frame thickness = 5, center = size / 2 = 23
// 7 tiles max (12 pixels size) on each side

static void	init_minimap(t_data *data, t_rect *player_rect)
{
	data->minimap.player.x = (int)data->player.pos.x;
	data->minimap.player.y = (int)data->player.pos.y;
	data->minimap.radius = 8;
	data->minimap.start.x = data->minimap.player.x - data->minimap.radius;
	data->minimap.end.x = data->minimap.player.x + data->minimap.radius;
	data->minimap.start.y = data->minimap.player.y - data->minimap.radius;
	data->minimap.end.y = data->minimap.player.y + data->minimap.radius + 1;
	data->minimap.offset.x = 0;
	data->minimap.offset.y = 0;
	data->minimap.pixel_offset.x = (data->player.pos.x - data->minimap.player.x)
		* MINIMAP_SCALE + player_rect->width / 2 * UPSCALING / 2;
	data->minimap.pixel_offset.y = (data->player.pos.y - data->minimap.player.y)
		* MINIMAP_SCALE + player_rect->height / 2 * UPSCALING / 2;
	if (data->minimap.start.x < 0)
	{
		data->minimap.offset.x = abs(data->minimap.start.x);
		data->minimap.start.x = 0;
	}
	if (data->minimap.start.y < 0)
	{
		data->minimap.offset.y = abs(data->minimap.start.y);
		data->minimap.start.y = 0;
	}
}

static void	draw_minimap(t_data *data)
{
	data->minimap.here.y = MINIMAP_OFFSET * UPSCALING + data->minimap.offset.y
		* MINIMAP_SCALE - data->minimap.pixel_offset.y;
	data->minimap.pos.y = data->minimap.start.y;
	while (data->minimap.pos.y < data->minimap.end.y
		&& data->minimap.pos.y < ft_tablen(data->map))
	{
		data->minimap.pos.x = data->minimap.start.x;
		data->minimap.here.x = MINIMAP_OFFSET * UPSCALING
			+ data->minimap.offset.x * MINIMAP_SCALE
			- data->minimap.pixel_offset.x;
		while (data->minimap.pos.x <= data->minimap.end.x
			&& data->map[data->minimap.pos.y][data->minimap.pos.x])
		{
			if (data->map[data->minimap.pos.y][data->minimap.pos.x] == WALL)
				put_img_to_frame(&data->frame, &data->texture.map_wall,
					data->minimap.here.x, data->minimap.here.y);
			else if (data->map[data->minimap.pos.y][data->minimap.pos.x] != ' ')
				put_img_to_frame(&data->frame, &data->texture.map_floor,
					data->minimap.here.x, data->minimap.here.y);
			data->minimap.here.x += MINIMAP_SCALE;
			data->minimap.pos.x++;
		}
		data->minimap.here.y += MINIMAP_SCALE;
		data->minimap.pos.y++;
	}
}

void	render_minimap(t_data *data)
{
	t_rect	player_rect;

	init_rect(&player_rect, MINIMAP_SCALE / 3, data->texture.minimap.width / 2
		* UPSCALING - MINIMAP_SCALE / 3 / 2, data->texture.minimap.height / 2
		* UPSCALING - MINIMAP_SCALE / 3 / 2);
	upscale_img(data, &data->texture.minimap, 0, 0);
	init_minimap(data, &player_rect);
	draw_minimap(data);
	draw_player_on_map(data, &player_rect);
	draw_enemies_on_map(data, &player_rect);
	upscale_img(data, &data->texture.map_frame, 0, 0);
}
