/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:49:42 by mivogel           #+#    #+#             */
/*   Updated: 2025/08/26 14:57:25 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	render_player_idle(t_data *data)
{
	int	breath_cycle;
	int	breath_offset;

	breath_cycle = g_frame_count % 120;
	breath_offset = (int)(sin(breath_cycle * 0.052f) * -2.5f);
	upscale_img(data, &data->texture.player_right1,
		WIN_WIDTH - (data->texture.player_right1.width * UPSCALING),
		WIN_HEIGHT + 2 - (data->texture.player_right1.height * UPSCALING)
		- breath_offset);
	upscale_img(data, &data->texture.player_left1,
		0,
		WIN_HEIGHT + 2 - (data->texture.player_left1.height * UPSCALING)
		- breath_offset);
}
