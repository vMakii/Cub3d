/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:42:48 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/22 14:39:13 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	load_fist(t_data *data)
{
	load_img(data, &data->texture.player_left1,
		"./assets/xpm/player/fist_l1.xpm");
	load_img(data, &data->texture.player_left2,
		"./assets/xpm/player/fist_l2.xpm");
	load_img(data, &data->texture.player_right1,
		"./assets/xpm/player/fist_r1.xpm");
	load_img(data, &data->texture.player_right2,
		"./assets/xpm/player/fist_r2.xpm");
	load_img(data, &data->texture.player_attack_0,
		"./assets/xpm/player/kick_0.xpm");
	load_img(data, &data->texture.player_attack_1,
		"./assets/xpm/player/kick_1.xpm");
	load_img(data, &data->texture.player_attack_2,
		"./assets/xpm/player/kick_2.xpm");
	load_img(data, &data->texture.player_attack_3,
		"./assets/xpm/player/kick_3.xpm");
	load_img(data, &data->texture.player_attack_4,
		"./assets/xpm/player/kick_4.xpm");
}

static void	load_sword(t_data *data)
{
	load_img(data, &data->texture.player_left1,
		"./assets/xpm/player/fist_l1.xpm");
	load_img(data, &data->texture.player_left2,
		"./assets/xpm/player/fist_l2.xpm");
	load_img(data, &data->texture.player_right1,
		"./assets/xpm/player/sword.xpm");
	load_img(data, &data->texture.player_right2,
		"./assets/xpm/player/sword.xpm");
	load_img(data, &data->texture.player_attack_0,
		"./assets/xpm/player/sword_0.xpm");
	load_img(data, &data->texture.player_attack_1,
		"./assets/xpm/player/sword_1.xpm");
	load_img(data, &data->texture.player_attack_2,
		"./assets/xpm/player/sword_2.xpm");
	load_img(data, &data->texture.player_attack_3,
		"./assets/xpm/player/sword_3.xpm");
	load_img(data, &data->texture.player_attack_4,
		"./assets/xpm/player/sword_4.xpm");
}

static void	load_magic_sword(t_data *data)
{
	load_img(data, &data->texture.player_left1,
		"./assets/xpm/player/fist_l1.xpm");
	load_img(data, &data->texture.player_left2,
		"./assets/xpm/player/fist_l2.xpm");
	load_img(data, &data->texture.player_right1,
		"./assets/xpm/player/magic_sword.xpm");
	load_img(data, &data->texture.player_right2,
		"./assets/xpm/player/magic_sword.xpm");
	load_img(data, &data->texture.player_attack_0,
		"./assets/xpm/player/magic_sword_0.xpm");
	load_img(data, &data->texture.player_attack_1,
		"./assets/xpm/player/magic_sword_1.xpm");
	load_img(data, &data->texture.player_attack_2,
		"./assets/xpm/player/magic_sword_2.xpm");
	load_img(data, &data->texture.player_attack_3,
		"./assets/xpm/player/magic_sword_3.xpm");
	load_img(data, &data->texture.player_attack_4,
		"./assets/xpm/player/magic_sword_4.xpm");
}

void	load_player(t_data *data)
{
	if (data->player.weapon.type == FIST)
		load_fist(data);
	else if (data->player.weapon.type == SWORD)
		load_sword(data);
	else if (data->player.weapon.type == MAGIC_SWORD)
		load_magic_sword(data);
	else
	{
		printf("Unknown weapon type: %d\n", data->player.weapon.type);
		exit_failure(data, "Unknown weapon type");
	}
}
