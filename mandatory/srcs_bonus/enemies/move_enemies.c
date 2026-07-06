/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:16:42 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/04 19:00:14 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	normalize_enemy_mov(t_coord_float *move, float unit)
{
	float	length;

	length = sqrtf(move->x * move->x + move->y * move->y);
	if (length > unit)
	{
		move->x = (move->x / length) * unit;
		move->y = (move->y / length) * unit;
	}
}

static void	calculate_enemy_new_position(t_data *data, t_enemy *enemy,
		t_coord_float *move)
{
	float	unit;

	if (enemy->state == DEAD || enemy->state == ATTACK || enemy->hp <= 0)
		unit = 0;
	else if (enemy->sprite->distance < 0.2f)
		unit = 0;
	else
		unit = enemy->speed * data->time.frametime * 60.0f;
	move->x -= unit * (enemy->sprite->pos.x - data->player.pos.x);
	move->y -= unit * (enemy->sprite->pos.y - data->player.pos.y);
	normalize_enemy_mov(move, unit);
}

static void	moving_enemy_position(t_data *data, t_enemy *enemy, float dx,
		float dy)
{
	int	new_x;
	int	new_y;

	new_y = (int)(enemy->sprite->pos.y);
	if (dx > 0)
		new_x = (int)(enemy->sprite->pos.x + dx + MARGIN);
	else if (dx < 0)
		new_x = (int)(enemy->sprite->pos.x + dx - MARGIN);
	else
		new_x = (int)(enemy->sprite->pos.x);
	if (new_x >= 0 && new_y >= 0 && data->map && data->map[new_y]
		&& data->map[new_y][new_x] && data->map[new_y][new_x] != WALL
		&& !is_door_blocking(data, new_x, new_y))
		enemy->sprite->pos.x += dx;
	new_x = (int)(enemy->sprite->pos.x);
	if (dy > 0)
		new_y = (int)(enemy->sprite->pos.y + dy + MARGIN);
	else if (dy < 0)
		new_y = (int)(enemy->sprite->pos.y + dy - MARGIN);
	else
		new_y = (int)(enemy->sprite->pos.y);
	if (new_x >= 0 && new_y >= 0 && data->map && data->map[new_y]
		&& data->map[new_y][new_x] && data->map[new_y][new_x] != WALL
		&& !is_door_blocking(data, new_x, new_y))
		enemy->sprite->pos.y += dy;
}

void	move_enemies(t_data *data)
{
	t_coord_float	move;
	t_enemy			*current;

	move.x = 0.0f;
	move.y = 0.0f;
	current = data->enemy;
	while (current)
	{
		if (current->sprite->distance < 80 && current->state != DEAD
			&& current->state != ATTACK && current->state != DAMAGED)
		{
			if (current->sprite->distance < 10
				|| (current->sprite->distance > 10
					&& can_see_player(data, current)))
			{
				calculate_enemy_new_position(data, current, &move);
				moving_enemy_position(data, current, move.x, move.y);
			}
		}
		current = current->next;
	}
}
