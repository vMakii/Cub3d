/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:44:24 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/05 10:59:15 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	moving_angle(t_player *player, float unit)
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

	if (dx > 0)
		new_x = (int)(data->player.pos.x + dx + MARGIN);
	else if (dx < 0)
		new_x = (int)(data->player.pos.x + dx - MARGIN);
	else
		new_x = (int)(data->player.pos.x);
	new_y = (int)(data->player.pos.y);
	if (new_x >= 0 && new_y >= 0 && data->map && data->map[new_y]
		&& data->map[new_y][new_x] && data->map[new_y][new_x] != WALL)
		data->player.pos.x += dx;
	new_x = (int)(data->player.pos.x);
	if (dy > 0)
		new_y = (int)(data->player.pos.y + dy + MARGIN);
	else if (dy < 0)
		new_y = (int)(data->player.pos.y + dy - MARGIN);
	else
		new_y = (int)(data->player.pos.y);
	if (new_x >= 0 && new_y >= 0 && data->map && data->map[new_y]
		&& data->map[new_y][new_x] && data->map[new_y][new_x] != WALL)
		data->player.pos.y += dy;
}

static void	calculate_move(t_data *data, t_coord_float *move, float unit)
{
	if (data->keys.key_w)
	{
		move->x += unit * data->player.dir.x;
		move->y += unit * data->player.dir.y;
	}
	if (data->keys.key_s)
	{
		move->x -= unit * data->player.dir.x;
		move->y -= unit * data->player.dir.y;
	}
	if (data->keys.key_d)
	{
		move->x -= unit * data->player.dir.y;
		move->y += unit * data->player.dir.x;
	}
	if (data->keys.key_a)
	{
		move->x += unit * data->player.dir.y;
		move->y -= unit * data->player.dir.x;
	}
}

void	player_move(t_data *data)
{
	float			unit;
	t_coord_float	move;
	float			length;

	unit = WALK_SPEED;
	move.x = 0.0f;
	move.y = 0.0f;
	calculate_move(data, &move, unit);
	length = sqrtf(move.x * move.x + move.y * move.y);
	if (length > unit)
	{
		move.x = (move.x / length) * unit;
		move.y = (move.y / length) * unit;
	}
	if (move.x != 0.0f || move.y != 0.0f)
		moving_position(data, move.x, move.y);
	if (data->keys.key_left)
		moving_angle(&data->player, -TURN_SPEED);
	if (data->keys.key_right)
		moving_angle(&data->player, TURN_SPEED);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		exit_success(data);
	if (keysym == XK_w || keysym == XK_Up)
		data->keys.key_w = 1;
	else if (keysym == XK_s || keysym == XK_Down)
		data->keys.key_s = 1;
	else if (keysym == XK_a)
		data->keys.key_a = 1;
	else if (keysym == XK_d)
		data->keys.key_d = 1;
	else if (keysym == XK_Left)
		data->keys.key_left = 1;
	else if (keysym == XK_Right)
		data->keys.key_right = 1;
	return (0);
}
