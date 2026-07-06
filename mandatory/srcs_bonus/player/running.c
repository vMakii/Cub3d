/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:16:54 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/21 15:50:34 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	running_animation_2(t_data *data, int running_cycle)
{
	if (running_cycle == 4)
	{
		upscale_img(data, &data->texture.player_right1, WIN_WIDTH
			- (data->texture.player_right1.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_right1.height * UPSCALING));
		upscale_img(data, &data->texture.player_left1, 0, WIN_HEIGHT
			- (data->texture.player_left1.height * UPSCALING));
	}
	else if (running_cycle == 5)
	{
		upscale_img(data, &data->texture.player_right1, WIN_WIDTH
			- (data->texture.player_right1.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_right1.height * UPSCALING));
		upscale_img(data, &data->texture.player_left2, 0, WIN_HEIGHT
			- (data->texture.player_left2.height * UPSCALING));
	}
}

// Animation duration: 0.4 seconds total (0.1 seconds per phase)
// 4 phases for a full cycle
static void	running_animation_1(t_data *data, double *elapsed_time)
{
	int	running_cycle;

	running_cycle = (int)(*elapsed_time / 0.1) % 6;
	if (running_cycle == 0 || running_cycle == 1 || running_cycle == 2)
	{
		upscale_img(data, &data->texture.player_right1, WIN_WIDTH
			- (data->texture.player_right1.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_right1.height * UPSCALING));
		upscale_img(data, &data->texture.player_left1, 0, WIN_HEIGHT
			- (data->texture.player_left1.height * UPSCALING));
	}
	else if (running_cycle == 3)
	{
		upscale_img(data, &data->texture.player_right2, WIN_WIDTH
			- (data->texture.player_right2.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_right2.height * UPSCALING));
		upscale_img(data, &data->texture.player_left1, 0, WIN_HEIGHT
			- (data->texture.player_left1.height * UPSCALING));
	}
	else
		running_animation_2(data, running_cycle);
}

static bool	check_player_moved(t_data *data)
{
	static t_coord_float	old_pos;
	static t_coord_float	cur_pos;

	if (!old_pos.x && !old_pos.y)
	{
		old_pos.x = data->player.pos.x;
		old_pos.y = data->player.pos.y;
	}
	else
	{
		old_pos.x = cur_pos.x;
		old_pos.y = cur_pos.y;
	}
	cur_pos.x = data->player.pos.x;
	cur_pos.y = data->player.pos.y;
	if (cur_pos.x == old_pos.x && cur_pos.y == old_pos.y)
		return (false);
	return (true);
}

void	render_player_running(t_data *data, double current_time)
{
	static double	running_start_time = 0;
	double			elapsed_time;

	if (!check_player_moved(data))
		return (render_player_idle(data));
	if (running_start_time > 5.0)
		running_start_time = current_time;
	elapsed_time = current_time - running_start_time;
	running_animation_1(data, &elapsed_time);
}
