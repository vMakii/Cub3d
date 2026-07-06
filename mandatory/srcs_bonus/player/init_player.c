/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:54:40 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/26 14:13:50 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_player(t_data *data)
{
	data->player.action = IDLE;
	data->player.hp = 100;
	data->player.weapon.type = FIST;
	init_weapons(data);
	data->player.impact = 0;
	data->player.impact_effect = BASE;
	data->player.impact_zone = 0;
	data->player.magick.hand_left = &data->texture.player_cast_0_l;
	data->player.magick.hand_right = &data->texture.player_cast_0_r;
	data->player.magick.spell = &data->texture.player_magick_9;
	data->player.magick.casting = false;
	data->player.magick.casted = false;
	data->player.magick.cd = false;
}
