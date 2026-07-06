/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:17:34 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/25 17:26:30 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	reset_attack_animation(t_data *data, double *attack_start_time,
		int *was_attacking)
{
	if (!*was_attacking && data->player.action == ATTACKING)
	{
		*attack_start_time = get_time();
		data->player.impact = 0;
	}
}

void	attack_animation_2(t_data *data, int attack_cycle)
{
	if (attack_cycle == 3)
	{
		upscale_img(data, &data->texture.player_attack_3, WIN_WIDTH
			- (data->texture.player_attack_3.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_attack_3.height * UPSCALING));
		if (data->player.impact_zone)
			data->player.impact = 1;
	}
	else
	{
		upscale_img(data, &data->texture.player_attack_4, WIN_WIDTH
			- (data->texture.player_attack_4.width), WIN_HEIGHT
			- (data->texture.player_attack_4.height));
		upscale_img(data, &data->texture.player_attack_4, WIN_WIDTH
			- (data->texture.player_attack_4.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_attack_4.height * UPSCALING));
	}
}

// Animation duration: 0.5 seconds total (0.1 seconds per phase)
void	attack_animation_1(t_data *data, double elapsed_time)
{
	int	attack_cycle;

	attack_cycle = (int)(elapsed_time / 0.1) % 10;
	if (attack_cycle == 0)
	{
		upscale_img(data, &data->texture.player_attack_0, WIN_WIDTH
			- (data->texture.player_attack_0.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_attack_0.height * UPSCALING));
	}
	else if (attack_cycle == 1)
	{
		upscale_img(data, &data->texture.player_attack_1, WIN_WIDTH
			- (data->texture.player_attack_1.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_attack_1.height * UPSCALING));
	}
	else if (attack_cycle == 2)
	{
		upscale_img(data, &data->texture.player_attack_2, WIN_WIDTH
			- (data->texture.player_attack_2.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_attack_2.height * UPSCALING));
	}
	else
		attack_animation_2(data, attack_cycle);
}

// Animation ends after 0.5 seconds
void	check_attack_end(t_data *data, double elapsed_time, int *was_attacking)
{
	if (data->player.action == ATTACKING)
	{
		if (elapsed_time >= 0.5)
		{
			data->player.action = IDLE;
			data->player.impact = 0;
			*was_attacking = 0;
		}
		else
			*was_attacking = 1;
	}
	else
		*was_attacking = 0;
}

void	render_player_attacking(t_data *data, double current_time)
{
	static double	attack_start_time = 0;
	static int		was_attacking = 0;
	double			elapsed_time;

	data->player.impact = 0;
	reset_attack_animation(data, &attack_start_time, &was_attacking);
	elapsed_time = current_time - attack_start_time;
	attack_animation_1(data, elapsed_time);
	check_attack_end(data, elapsed_time, &was_attacking);
}
