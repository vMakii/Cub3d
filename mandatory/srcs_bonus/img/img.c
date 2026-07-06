/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:38:17 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/22 11:17:35 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	load_img(t_data *data, t_image *sprite, char *path)
{
	ft_memset(sprite, 0, sizeof(t_image));
	if (access(path, F_OK) == -1)
	{
		printf("Image file not found: %s\n", path);
		exit_failure(data, "Image file not found");
	}
	sprite->image = mlx_xpm_file_to_image(data->mlx.ptr, path, &sprite->width,
			&sprite->height);
	if (!sprite->image)
		exit_failure(data, "Failed to load image");
	sprite->data = mlx_get_data_addr(sprite->image, &sprite->bpp,
			&sprite->size_line, &sprite->endian);
	sprite->width = sprite->image->width;
	sprite->height = sprite->image->height;
}

void	init_img(t_data *data)
{
	ft_memset(&data->texture, 0, sizeof(t_texture));
	load_effects(data);
	load_enemies(data);
	load_player(data);
	load_magick(data);
	load_sprites(data);
	load_textures(data);
}

void	destroy_img(t_data *data)
{
	destroy_effects(data);
	destroy_enemies(data);
	destroy_player(data);
	destroy_magick(data);
	destroy_sprites(data);
	destroy_textures(data);
}
