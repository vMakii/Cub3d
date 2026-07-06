/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_effects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:51:46 by mivogel           #+#    #+#             */
/*   Updated: 2025/08/22 12:16:54 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	destroy_impact(t_data *data)
{
	if (data->texture.impact_0.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.impact_0.image);
	if (data->texture.impact_1.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.impact_1.image);
	if (data->texture.impact_2.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.impact_2.image);
	if (data->texture.impact_3.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.impact_3.image);
	if (data->texture.impact_4.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.impact_4.image);
}

static void	destroy_blood(t_data *data)
{
	if (data->texture.blood_0.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.blood_0.image);
	if (data->texture.blood_1.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.blood_1.image);
	if (data->texture.blood_2.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.blood_2.image);
	if (data->texture.blood_3.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.blood_3.image);
	if (data->texture.blood_4.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.blood_4.image);
}

static void	destroy_hit_screen(t_data *data)
{
	if (data->texture.hit.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.hit.image);
}

void	destroy_effects(t_data *data)
{
	destroy_impact(data);
	destroy_blood(data);
	destroy_hit_screen(data);
}
