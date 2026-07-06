/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:40:10 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/21 15:55:00 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	load_werewolf(t_data *data)
{
	load_img(data, &data->texture.werewolf_moving_0,
		"./assets/xpm/enemies/werewolf/0-0.xpm");
	load_img(data, &data->texture.werewolf_moving_1,
		"./assets/xpm/enemies/werewolf/0-1.xpm");
	load_img(data, &data->texture.werewolf_moving_2,
		"./assets/xpm/enemies/werewolf/0-2.xpm");
	load_img(data, &data->texture.werewolf_moving_3,
		"./assets/xpm/enemies/werewolf/0-3.xpm");
	load_img(data, &data->texture.werewolf_attack_0,
		"./assets/xpm/enemies/werewolf/5-0.xpm");
	load_img(data, &data->texture.werewolf_attack_1,
		"./assets/xpm/enemies/werewolf/5-1.xpm");
	load_img(data, &data->texture.werewolf_attack_2,
		"./assets/xpm/enemies/werewolf/5-2.xpm");
	load_img(data, &data->texture.werewolf_damaged,
		"./assets/xpm/enemies/werewolf/10-0.xpm");
	load_img(data, &data->texture.werewolf_dead,
		"./assets/xpm/enemies/werewolf/15-0.xpm");
}

static void	load_skeleton(t_data *data)
{
	load_img(data, &data->texture.skeleton_moving_0,
		"./assets/xpm/enemies/skeleton/0-0.xpm");
	load_img(data, &data->texture.skeleton_moving_1,
		"./assets/xpm/enemies/skeleton/0-1.xpm");
	load_img(data, &data->texture.skeleton_moving_2,
		"./assets/xpm/enemies/skeleton/0-2.xpm");
	load_img(data, &data->texture.skeleton_moving_3,
		"./assets/xpm/enemies/skeleton/0-3.xpm");
	load_img(data, &data->texture.skeleton_attack_0,
		"./assets/xpm/enemies/skeleton/5-0.xpm");
	load_img(data, &data->texture.skeleton_attack_1,
		"./assets/xpm/enemies/skeleton/5-1.xpm");
	load_img(data, &data->texture.skeleton_attack_2,
		"./assets/xpm/enemies/skeleton/5-2.xpm");
	load_img(data, &data->texture.skeleton_attack_3,
		"./assets/xpm/enemies/skeleton/5-3.xpm");
	load_img(data, &data->texture.skeleton_attack_4,
		"./assets/xpm/enemies/skeleton/5-4.xpm");
	load_img(data, &data->texture.skeleton_attack_5,
		"./assets/xpm/enemies/skeleton/5-5.xpm");
	load_img(data, &data->texture.skeleton_damaged,
		"./assets/xpm/enemies/skeleton/10-0.xpm");
	load_img(data, &data->texture.skeleton_dead,
		"./assets/xpm/enemies/skeleton/20-0.xpm");
}

static void	load_zombie1(t_data *data)
{
	load_img(data, &data->texture.zombie_attack_0,
		"./assets/xpm/enemies/zombie/5-0.xpm");
	load_img(data, &data->texture.zombie_attack_1,
		"./assets/xpm/enemies/zombie/5-1.xpm");
	load_img(data, &data->texture.zombie_attack_2,
		"./assets/xpm/enemies/zombie/5-2.xpm");
	load_img(data, &data->texture.zombie_attack_3,
		"./assets/xpm/enemies/zombie/5-3.xpm");
	load_img(data, &data->texture.zombie_attack_4,
		"./assets/xpm/enemies/zombie/5-4.xpm");
	load_img(data, &data->texture.zombie_damaged,
		"./assets/xpm/enemies/zombie/10-0.xpm");
	load_img(data, &data->texture.zombie_dead,
		"./assets/xpm/enemies/zombie/20-0.xpm");
}

static void	load_zombie(t_data *data)
{
	load_img(data, &data->texture.zombie_moving_0,
		"./assets/xpm/enemies/zombie/0-0.xpm");
	load_img(data, &data->texture.zombie_moving_1,
		"./assets/xpm/enemies/zombie/0-1.xpm");
	load_img(data, &data->texture.zombie_moving_2,
		"./assets/xpm/enemies/zombie/0-2.xpm");
	load_img(data, &data->texture.zombie_moving_3,
		"./assets/xpm/enemies/zombie/0-3.xpm");
	load_img(data, &data->texture.zombie_moving_4,
		"./assets/xpm/enemies/zombie/0-4.xpm");
	load_img(data, &data->texture.zombie_moving_5,
		"./assets/xpm/enemies/zombie/0-5.xpm");
	load_img(data, &data->texture.zombie_moving_6,
		"./assets/xpm/enemies/zombie/0-6.xpm");
	load_img(data, &data->texture.zombie_moving_7,
		"./assets/xpm/enemies/zombie/0-7.xpm");
	load_zombie1(data);
}

void	load_enemies(t_data *data)
{
	load_werewolf(data);
	load_skeleton(data);
	load_zombie(data);
}
