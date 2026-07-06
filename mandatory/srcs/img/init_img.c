/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:25:26 by mivogel           #+#    #+#             */
/*   Updated: 2025/08/05 17:35:32 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_img(t_data *data, t_image *sprite, char *path)
{
	ft_memset(sprite, 0, sizeof(t_image));
	sprite->image = mlx_xpm_file_to_image(data->mlx.ptr, path, &sprite->width,
			&sprite->height);
	if (!sprite->image)
		exit_failure(data, "Failed to load image");
	sprite->data = mlx_get_data_addr(sprite->image, &sprite->bpp,
			&sprite->size_line, &sprite->endian);
	sprite->width = sprite->image->width;
	sprite->height = sprite->image->height;
}

static void	loader(t_data *data)
{
	load_img(data, &data->sprite.north, data->texture.north_texture);
	load_img(data, &data->sprite.south, data->texture.south_texture);
	load_img(data, &data->sprite.west, data->texture.west_texture);
	load_img(data, &data->sprite.east, data->texture.east_texture);
}

void	init_img(t_data *data)
{
	ft_memset(&data->sprite, 0, sizeof(t_sprite));
	loader(data);
}
