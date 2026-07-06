/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:40:12 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/02 12:43:22 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	update_spell_effect(t_data *data)
{
	if (data->player.magick.spell == &data->texture.player_magick_0)
		data->player.magick.spell = &data->texture.player_magick_1;
	else if (data->player.magick.spell == &data->texture.player_magick_1)
		data->player.magick.spell = &data->texture.player_magick_2;
	else if (data->player.magick.spell == &data->texture.player_magick_2)
		data->player.magick.spell = &data->texture.player_magick_3;
	else if (data->player.magick.spell == &data->texture.player_magick_3)
		data->player.magick.spell = &data->texture.player_magick_4;
	else if (data->player.magick.spell == &data->texture.player_magick_4)
		data->player.magick.spell = &data->texture.player_magick_5;
	else if (data->player.magick.spell == &data->texture.player_magick_5)
		data->player.magick.spell = &data->texture.player_magick_6;
	else if (data->player.magick.spell == &data->texture.player_magick_6)
		data->player.magick.spell = &data->texture.player_magick_7;
	else if (data->player.magick.spell == &data->texture.player_magick_7)
		data->player.magick.spell = &data->texture.player_magick_8;
	else if (data->player.magick.spell == &data->texture.player_magick_8)
		data->player.magick.spell = &data->texture.player_magick_9;
	else
	{
		data->player.magick.spell = &data->texture.player_magick_0;
		data->player.magick.casting = false;
		data->player.magick.cd = false;
	}
}

void	render_spell_effect(t_data *data)
{
	int	spell_x;
	int	spell_y;

	spell_x = (WIN_WIDTH / 2) - (data->player.magick.spell->width / 2)
		* UPSCALING;
	spell_y = (WIN_HEIGHT / 2) - (data->player.magick.spell->height / 2)
		* UPSCALING + 30 * UPSCALING;
	if (g_frame_count % 5 == 0)
	{
		update_spell_effect(data);
		if (data->player.weapon.type == FIST)
			data->player.hp += 2;
		else
			data->player.hp += 1;
		if (data->player.hp > 100)
			data->player.hp = 100;
	}
	upscale_img(data, data->player.magick.spell, spell_x, spell_y);
}
