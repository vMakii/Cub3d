/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_enemies.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:55:37 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/03 12:47:45 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_enemies(t_data *data, t_rect *player_rect, t_enemies_on_map *e)
{
	e->map_pos.x = (player_rect->pos.x) + (e->relative_pos.x * MINIMAP_SCALE);
	e->map_pos.y = (player_rect->pos.y) + (e->relative_pos.y * MINIMAP_SCALE);
	init_rect(&e->rect, MINIMAP_SCALE / 3, e->map_pos.x, e->map_pos.y);
	draw_rect(&data->frame, e->rect, COLOR_RED);
}

void	draw_enemies_on_map(t_data *data, t_rect *player_rect)
{
	t_enemy				*enemy;
	t_enemies_on_map	e;

	enemy = data->enemy;
	while (enemy)
	{
		e.relative_pos.x = enemy->sprite->pos.x - data->player.pos.x;
		e.relative_pos.y = enemy->sprite->pos.y - data->player.pos.y;
		if (enemy->state != DEAD && e.relative_pos.x > -data->minimap.radius
			&& e.relative_pos.x < data->minimap.radius
			&& e.relative_pos.y > -data->minimap.radius
			&& e.relative_pos.y < data->minimap.radius)
		{
			draw_enemies(data, player_rect, &e);
		}
		enemy = enemy->next;
	}
}
