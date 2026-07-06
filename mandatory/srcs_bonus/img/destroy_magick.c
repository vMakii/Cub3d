/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_magick.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:14:28 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/02 11:15:10 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	destroy_hand_left(t_data *data)
{
	if (data->texture.player_cast_0_l.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_cast_0_l.image);
	if (data->texture.player_cast_1_l.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_cast_1_l.image);
	if (data->texture.player_cast_2_l.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_cast_2_l.image);
	if (data->texture.player_cast_3_l.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_cast_3_l.image);
	if (data->texture.player_cast_4_l.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_cast_4_l.image);
	if (data->texture.player_cast_5_l.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_cast_5_l.image);
}

void	destroy_hand_right(t_data *data)
{
	if (data->texture.player_cast_0_r.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_cast_0_r.image);
	if (data->texture.player_cast_1_r.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_cast_1_r.image);
	if (data->texture.player_cast_2_r.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_cast_2_r.image);
	if (data->texture.player_cast_3_r.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_cast_3_r.image);
	if (data->texture.player_cast_4_r.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_cast_4_r.image);
	if (data->texture.player_cast_5_r.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_cast_5_r.image);
}

void	destroy_spell_effects(t_data *data)
{
	if (data->texture.player_magick_0.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_magick_0.image);
	if (data->texture.player_magick_1.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_magick_1.image);
	if (data->texture.player_magick_2.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_magick_2.image);
	if (data->texture.player_magick_3.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_magick_3.image);
	if (data->texture.player_magick_4.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_magick_4.image);
	if (data->texture.player_magick_5.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_magick_5.image);
	if (data->texture.player_magick_6.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_magick_6.image);
	if (data->texture.player_magick_7.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_magick_7.image);
	if (data->texture.player_magick_8.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_magick_8.image);
	if (data->texture.player_magick_9.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.player_magick_9.image);
}

void	destroy_magick(t_data *data)
{
	destroy_hand_left(data);
	destroy_hand_right(data);
	destroy_spell_effects(data);
}
