/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impact.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:12:09 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/02 11:24:13 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	reset_impact_animation(t_data *data, int *impact_frame,
		int *last_impact_state)
{
	if (!*last_impact_state && data->player.impact)
	{
		*impact_frame = 0;
		*last_impact_state = 1;
	}
	else if (*last_impact_state && !data->player.impact)
	{
		*last_impact_state = 0;
	}
}

// 5 phases, 6 frames par phase = 30 frames total
static void	impact_animation(t_data *data, int impact_frame)
{
	int	impact_cycle;
	int	impact_x;
	int	impact_y;

	impact_cycle = (impact_frame / 6) % 5;
	impact_x = (WIN_WIDTH / 2) - (data->texture.impact_0.width / 2) - 55;
	impact_y = (WIN_HEIGHT / 2) - (data->texture.impact_0.height / 2) - 30;
	if (impact_cycle == 0)
		upscale_img(data, &data->texture.impact_0, impact_x, impact_y);
	else if (impact_cycle == 1)
		upscale_img(data, &data->texture.impact_1, impact_x, impact_y);
	else if (impact_cycle == 2)
		upscale_img(data, &data->texture.impact_2, impact_x, impact_y);
	else if (impact_cycle == 3)
		upscale_img(data, &data->texture.impact_3, impact_x, impact_y);
	else if (impact_cycle == 4)
		upscale_img(data, &data->texture.impact_4, impact_x, impact_y);
}

static void	blood_animation(t_data *data, int impact_frame)
{
	int	blood_cycle;
	int	blood_x;
	int	blood_y;

	blood_cycle = (impact_frame / 6) % 5;
	blood_x = (WIN_WIDTH / 2) - (data->texture.blood_0.width / 2) - 100;
	blood_y = (WIN_HEIGHT / 2) - (data->texture.blood_0.height / 2) - 20;
	if (blood_cycle == 0)
		upscale_img(data, &data->texture.blood_0, blood_x, blood_y);
	else if (blood_cycle == 1)
		upscale_img(data, &data->texture.blood_1, blood_x, blood_y);
	else if (blood_cycle == 2)
		upscale_img(data, &data->texture.blood_2, blood_x, blood_y);
	else if (blood_cycle == 3)
		upscale_img(data, &data->texture.blood_3, blood_x, blood_y);
	else if (blood_cycle == 4)
		upscale_img(data, &data->texture.blood_4, blood_x, blood_y);
}

static void	increment_impact_frame(t_data *data, int *impact_frame,
		int *last_impact_state)
{
	if (data->player.impact || *impact_frame > 0)
	{
		(*impact_frame)++;
		if (*impact_frame >= 30)
		{
			data->player.impact = 0;
			*impact_frame = 0;
			*last_impact_state = 0;
		}
	}
}

void	render_impact_effect(t_data *data)
{
	static int	impact_frame = 0;
	static int	last_impact_state = 0;

	reset_impact_animation(data, &impact_frame, &last_impact_state);
	if (data->player.impact || impact_frame > 0)
	{
		if (data->player.impact_effect == BASE)
			impact_animation(data, impact_frame);
		else if (data->player.impact_effect == BLOOD)
			blood_animation(data, impact_frame);
		increment_impact_frame(data, &impact_frame, &last_impact_state);
	}
}
