/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_enemies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:58:49 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/21 15:55:32 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	destroy_werewolf(t_data *data)
{
	if (data->texture.werewolf_moving_0.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.werewolf_moving_0.image);
	if (data->texture.werewolf_moving_1.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.werewolf_moving_1.image);
	if (data->texture.werewolf_moving_2.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.werewolf_moving_2.image);
	if (data->texture.werewolf_moving_3.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.werewolf_moving_3.image);
	if (data->texture.werewolf_attack_0.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.werewolf_attack_0.image);
	if (data->texture.werewolf_attack_1.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.werewolf_attack_1.image);
	if (data->texture.werewolf_attack_2.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.werewolf_attack_2.image);
	if (data->texture.werewolf_damaged.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.werewolf_damaged.image);
	if (data->texture.werewolf_dead.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.werewolf_dead.image);
}

static void	destroy_skeleton(t_data *data)
{
	if (data->texture.skeleton_moving_0.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.skeleton_moving_0.image);
	if (data->texture.skeleton_moving_1.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.skeleton_moving_1.image);
	if (data->texture.skeleton_moving_2.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.skeleton_moving_2.image);
	if (data->texture.skeleton_moving_3.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.skeleton_moving_3.image);
	if (data->texture.skeleton_attack_0.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.skeleton_attack_0.image);
	if (data->texture.skeleton_attack_1.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.skeleton_attack_1.image);
	if (data->texture.skeleton_attack_2.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.skeleton_attack_2.image);
	if (data->texture.skeleton_attack_3.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.skeleton_attack_3.image);
	if (data->texture.skeleton_attack_4.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.skeleton_attack_4.image);
	if (data->texture.skeleton_attack_5.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.skeleton_attack_5.image);
	if (data->texture.skeleton_damaged.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.skeleton_damaged.image);
	if (data->texture.skeleton_dead.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.skeleton_dead.image);
}

static void	destroy_zombie1(t_data *data)
{
	if (data->texture.zombie_attack_0.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.zombie_attack_0.image);
	if (data->texture.zombie_attack_1.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.zombie_attack_1.image);
	if (data->texture.zombie_attack_2.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.zombie_attack_2.image);
	if (data->texture.zombie_attack_3.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.zombie_attack_3.image);
	if (data->texture.zombie_attack_4.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.zombie_attack_4.image);
	if (data->texture.zombie_damaged.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.zombie_damaged.image);
	if (data->texture.zombie_dead.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.zombie_dead.image);
}

static void	destroy_zombie(t_data *data)
{
	if (data->texture.zombie_moving_0.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.zombie_moving_0.image);
	if (data->texture.zombie_moving_1.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.zombie_moving_1.image);
	if (data->texture.zombie_moving_2.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.zombie_moving_2.image);
	if (data->texture.zombie_moving_3.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.zombie_moving_3.image);
	if (data->texture.zombie_moving_4.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.zombie_moving_4.image);
	if (data->texture.zombie_moving_5.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.zombie_moving_5.image);
	if (data->texture.zombie_moving_6.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.zombie_moving_6.image);
	if (data->texture.zombie_moving_7.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.zombie_moving_7.image);
	destroy_zombie1(data);
}

void	destroy_enemies(t_data *data)
{
	destroy_werewolf(data);
	destroy_skeleton(data);
	destroy_zombie(data);
}
