/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:44:08 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/09 10:54:05 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	mouse_x_limits(t_data *data, t_coord_int *current_pos,
	t_coord_int *last_pos)
{
	if (current_pos->x >= WIN_WIDTH)
	{
		current_pos->x = 1;
		last_pos->x = 0;
		mlx_mouse_move(data->mlx.ptr, data->mlx.win, current_pos->x,
			current_pos->y);
	}
	if (current_pos->x <= 0)
	{
		current_pos->x = WIN_WIDTH -1;
		last_pos->x = WIN_WIDTH;
		mlx_mouse_move(data->mlx.ptr, data->mlx.win, current_pos->x,
			current_pos->y);
	}
}

static void	mouse_y_limits(t_data *data, t_coord_int *current_pos,
	t_coord_int *last_pos)
{
	if (current_pos->y >= WIN_HEIGHT - 100)
	{
		current_pos->y = 101;
		last_pos->y = 100;
		mlx_mouse_move(data->mlx.ptr, data->mlx.win, current_pos->x,
			current_pos->y);
	}
	if (current_pos->y <= 100)
	{
		current_pos->y = WIN_HEIGHT - 100;
		last_pos->y = WIN_HEIGHT - 99;
		mlx_mouse_move(data->mlx.ptr, data->mlx.win, current_pos->x,
			current_pos->y);
	}
}

int	mouse_hook(t_data *data)
{
	static t_coord_int	last_pos = {0, 0};
	static bool			first_call = true;
	t_coord_int			current_pos;
	float				turn_speed;

	mlx_mouse_hide(data->mlx.ptr, data->mlx.win);
	mlx_mouse_get_pos(data->mlx.ptr, data->mlx.win, &current_pos.x,
		&current_pos.y);
	if (first_call)
	{
		last_pos = current_pos;
		first_call = false;
		return (0);
	}
	mouse_x_limits(data, &current_pos, &last_pos);
	mouse_y_limits(data, &current_pos, &last_pos);
	if (current_pos.x != last_pos.x)
	{
		turn_speed = 0.002 * (current_pos.x - last_pos.x);
		moving_angle(&data->player, turn_speed);
	}
	last_pos = current_pos;
	return (0);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1 && data->player.action != ATTACKING)
		data->player.action = ATTACKING;
	return (0);
}
