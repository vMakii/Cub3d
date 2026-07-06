/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:54:00 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/19 21:38:00 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	destroy_player_animations(t_data *data)
{
	if (data->texture.player_left1.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_left1.image);
	if (data->texture.player_left2.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_left2.image);
	if (data->texture.player_right1.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_right1.image);
	if (data->texture.player_right2.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_right2.image);
	if (data->texture.player_attack_0.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_attack_0.image);
	if (data->texture.player_attack_1.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_attack_1.image);
	if (data->texture.player_attack_2.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_attack_2.image);
	if (data->texture.player_attack_3.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_attack_3.image);
	if (data->texture.player_attack_4.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_attack_4.image);
}

void	destroy_player(t_data *data)
{
	destroy_player_animations(data);
}
