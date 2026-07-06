/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 19:27:44 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/03 12:48:35 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	moving_angle(t_player *player, float unit)
{
	player->angle += unit;
	player->dir.x = cosf(player->angle);
	player->dir.y = sinf(player->angle);
	player->plane.x = -player->dir.y * 0.66f;
	player->plane.y = player->dir.x * 0.66f;
}

static void	moving_position(t_data *data, float dx, float dy)
{
	int	new_x;
	int	new_y;

	new_y = (int)(data->player.pos.y);
	if (dx > 0)
		new_x = (int)(data->player.pos.x + dx + MARGIN);
	else if (dx < 0)
		new_x = (int)(data->player.pos.x + dx - MARGIN);
	else
		new_x = (int)(data->player.pos.x);
	if (new_x >= 0 && new_y >= 0 && data->map[new_y] && data->map[new_y][new_x]
		&& data->map[new_y][new_x] != WALL && !is_door_blocking(data, new_x,
			new_y) && !is_enemy_blocking(data, new_x, new_y))
		data->player.pos.x += dx;
	new_x = (int)(data->player.pos.x);
	if (dy > 0)
		new_y = (int)(data->player.pos.y + dy + MARGIN);
	else if (dy < 0)
		new_y = (int)(data->player.pos.y + dy - MARGIN);
	else
		new_y = (int)(data->player.pos.y);
	if (new_x >= 0 && new_y >= 0 && data->map[new_y] && data->map[new_y][new_x]
		&& data->map[new_y][new_x] != WALL && !is_door_blocking(data, new_x,
			new_y) && !is_enemy_blocking(data, new_x, new_y))
		data->player.pos.y += dy;
}

void	player_move(t_data *data)
{
	t_coord_float	move;

	move.x = 0.0f;
	move.y = 0.0f;
	calculate_new_position(data, &move);
	if (move.x != 0.0f || move.y != 0.0f)
	{
		if (data->player.action != ATTACKING && data->player.action != RUNNING
			&& data->player.action != CASTING)
			data->player.action = WALKING;
		moving_position(data, move.x, move.y);
	}
	if (data->keys.key_left)
		moving_angle(&data->player, -TURN_SPEED * data->time.frametime * 66.0f);
	if (data->keys.key_right)
		moving_angle(&data->player, TURN_SPEED * data->time.frametime * 66.0f);
	mouse_hook(data);
}
