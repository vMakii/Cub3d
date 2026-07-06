/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:21:00 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/19 20:23:55 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	destroy_ceiling_sprites(t_data *data)
{
	int	i;

	i = 0;
	while (i < NB_SPRITES_C)
	{
		if (data->texture.sprites_ceiling[i].image)
			mlx_destroy_image(data->mlx.ptr,
				data->texture.sprites_ceiling[i].image);
		i++;
	}
}

static void	destroy_floor_sprites(t_data *data)
{
	int	i;

	i = 0;
	while (i < NB_SPRITES_F)
	{
		if (data->texture.sprites_floor[i].image)
			mlx_destroy_image(data->mlx.ptr,
				data->texture.sprites_floor[i].image);
		i++;
	}
}

static void	destroy_lamp_sprites(t_data *data)
{
	if (data->texture.lamp_0.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.lamp_0.image);
	if (data->texture.lamp_1.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.lamp_1.image);
	if (data->texture.lamp_2.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.lamp_2.image);
	if (data->texture.lamp_3.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.lamp_3.image);
}

static void	destroy_treasure_sprites(t_data *data)
{
	if (data->texture.treasure.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.treasure.image);
}

void	destroy_sprites(t_data *data)
{
	destroy_ceiling_sprites(data);
	destroy_floor_sprites(data);
	destroy_lamp_sprites(data);
	destroy_treasure_sprites(data);
}
