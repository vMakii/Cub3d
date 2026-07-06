/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magick.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:59:54 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/02 12:44:25 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	update_casting_animation2(t_data *data)
{
	if (data->player.magick.hand_left == &data->texture.player_cast_3_l)
	{
		data->player.magick.hand_left = &data->texture.player_cast_4_l;
		data->player.magick.hand_right = &data->texture.player_cast_4_r;
	}
	else if (data->player.magick.hand_left == &data->texture.player_cast_4_l)
	{
		data->player.magick.hand_left = &data->texture.player_cast_5_l;
		data->player.magick.hand_right = &data->texture.player_cast_5_r;
		data->player.magick.casted = true;
	}
}

void	update_casting_animation(t_data *data)
{
	if (data->player.magick.hand_left == &data->texture.player_cast_0_l)
	{
		data->player.magick.hand_left = &data->texture.player_cast_1_l;
		data->player.magick.hand_right = &data->texture.player_cast_1_r;
	}
	else if (data->player.magick.hand_left == &data->texture.player_cast_1_l)
	{
		data->player.magick.hand_left = &data->texture.player_cast_2_l;
		data->player.magick.hand_right = &data->texture.player_cast_2_r;
	}
	else if (data->player.magick.hand_left == &data->texture.player_cast_2_l)
	{
		data->player.magick.hand_left = &data->texture.player_cast_3_l;
		data->player.magick.hand_right = &data->texture.player_cast_3_r;
	}
	else
		update_casting_animation2(data);
}

void	define_offset(t_data *data, int *offset, int *dir)
{
	if (g_frame_count % 5 == 0
		&& data->player.magick.hand_left == &data->texture.player_cast_5_l)
	{
		if (*offset == 5)
			*dir = 1;
		if (*offset == 0)
			*dir = 0;
		if (*dir == 0)
			(*offset)++;
		else
			(*offset)--;
	}
}

void	render_player_casting(t_data *data)
{
	static int	offset = 0;
	static int	dir = 1;

	if (g_frame_count % 5 == 0)
	{
		update_casting_animation(data);
	}
	define_offset(data, &offset, &dir);
	upscale_img(data, data->player.magick.hand_left, 0 - offset, WIN_HEIGHT
		- (data->player.magick.hand_left->height * UPSCALING) + offset);
	if (data->player.weapon.type == FIST)
		upscale_img(data, data->player.magick.hand_right, WIN_WIDTH
			- (data->player.magick.hand_right->width * UPSCALING) + offset,
			WIN_HEIGHT - (data->player.magick.hand_right->height * UPSCALING)
			+ offset);
	else
	{
		upscale_img(data, &data->texture.player_right1, WIN_WIDTH
			- (data->texture.player_right1.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_right1.height * UPSCALING) + offset);
	}
}

void	render_player_magick(t_data *data)
{
	data->player.magick.casting = true;
	render_player_casting(data);
	if (data->player.magick.casted)
		render_spell_effect(data);
}
