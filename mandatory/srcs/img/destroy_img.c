/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:48:15 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/05 11:53:48 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_img1(t_data *data)
{
	if (data->sprite.north.image)
		mlx_destroy_image(data->mlx.ptr, data->sprite.north.image);
	if (data->sprite.south.image)
		mlx_destroy_image(data->mlx.ptr, data->sprite.south.image);
	if (data->sprite.east.image)
		mlx_destroy_image(data->mlx.ptr, data->sprite.east.image);
	if (data->sprite.west.image)
		mlx_destroy_image(data->mlx.ptr, data->sprite.west.image);
}

void	destroy_img(t_data *data)
{
	destroy_img1(data);
}
