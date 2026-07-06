/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_magick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:06:12 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/02 11:15:23 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	load_hand_left(t_data *data)
{
	load_img(data, &data->texture.player_cast_0_l,
		"./assets/xpm/magick/hand/0-0.xpm");
	load_img(data, &data->texture.player_cast_1_l,
		"./assets/xpm/magick/hand/1-0.xpm");
	load_img(data, &data->texture.player_cast_2_l,
		"./assets/xpm/magick/hand/2-0.xpm");
	load_img(data, &data->texture.player_cast_3_l,
		"./assets/xpm/magick/hand/3-0.xpm");
	load_img(data, &data->texture.player_cast_4_l,
		"./assets/xpm/magick/hand/4-0.xpm");
	load_img(data, &data->texture.player_cast_5_l,
		"./assets/xpm/magick/hand/5-0.xpm");
}

void	load_hand_right(t_data *data)
{
	load_img(data, &data->texture.player_cast_0_r,
		"./assets/xpm/magick/hand/0-1.xpm");
	load_img(data, &data->texture.player_cast_1_r,
		"./assets/xpm/magick/hand/1-1.xpm");
	load_img(data, &data->texture.player_cast_2_r,
		"./assets/xpm/magick/hand/2-1.xpm");
	load_img(data, &data->texture.player_cast_3_r,
		"./assets/xpm/magick/hand/3-1.xpm");
	load_img(data, &data->texture.player_cast_4_r,
		"./assets/xpm/magick/hand/4-1.xpm");
	load_img(data, &data->texture.player_cast_5_r,
		"./assets/xpm/magick/hand/5-1.xpm");
}

void	load_spell_effects(t_data *data)
{
	load_img(data, &data->texture.player_magick_0,
		"./assets/xpm/magick/spell/0-0.xpm");
	load_img(data, &data->texture.player_magick_1,
		"./assets/xpm/magick/spell/0-1.xpm");
	load_img(data, &data->texture.player_magick_2,
		"./assets/xpm/magick/spell/0-2.xpm");
	load_img(data, &data->texture.player_magick_3,
		"./assets/xpm/magick/spell/0-3.xpm");
	load_img(data, &data->texture.player_magick_4,
		"./assets/xpm/magick/spell/0-4.xpm");
	load_img(data, &data->texture.player_magick_5,
		"./assets/xpm/magick/spell/0-5.xpm");
	load_img(data, &data->texture.player_magick_6,
		"./assets/xpm/magick/spell/0-6.xpm");
	load_img(data, &data->texture.player_magick_7,
		"./assets/xpm/magick/spell/0-7.xpm");
	load_img(data, &data->texture.player_magick_8,
		"./assets/xpm/magick/spell/0-8.xpm");
	load_img(data, &data->texture.player_magick_9,
		"./assets/xpm/magick/spell/0-9.xpm");
}

void	load_magick(t_data *data)
{
	load_hand_left(data);
	load_hand_right(data);
	load_spell_effects(data);
}
