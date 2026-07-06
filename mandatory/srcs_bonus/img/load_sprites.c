/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:45:11 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/20 14:51:16 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	load_ceiling_sprites(t_data *data)
{
	int		i;
	char	*nb;
	char	*tmp;
	char	*path;

	i = 1;
	while (i <= NB_SPRITES_C)
	{
		nb = ft_itoa(i);
		tmp = ft_strjoin("./assets/xpm/sprites/indoor/ceiling/", nb);
		free(nb);
		path = ft_strjoin(tmp, ".xpm");
		free(tmp);
		load_img(data, &data->texture.sprites_ceiling[i - 1], path);
		free(path);
		i++;
	}
}

static void	load_floor_sprites(t_data *data)
{
	int		i;
	char	*nb;
	char	*tmp;
	char	*path;

	i = 1;
	while (i <= NB_SPRITES_F)
	{
		nb = ft_itoa(i);
		tmp = ft_strjoin("./assets/xpm/sprites/indoor/floor/", nb);
		free(nb);
		path = ft_strjoin(tmp, ".xpm");
		free(tmp);
		load_img(data, &data->texture.sprites_floor[i - 1], path);
		free(path);
		i++;
	}
}

static void	load_lamps_sprites(t_data *data)
{
	load_img(data, &data->texture.lamp_0,
		"./assets/xpm/sprites/church/lights/1_0.xpm");
	load_img(data, &data->texture.lamp_1,
		"./assets/xpm/sprites/church/lights/1_1.xpm");
	load_img(data, &data->texture.lamp_2,
		"./assets/xpm/sprites/church/lights/1_2.xpm");
	load_img(data, &data->texture.lamp_3,
		"./assets/xpm/sprites/church/lights/1_3.xpm");
}

static void	load_treasure_sprites(t_data *data)
{
	load_img(data, &data->texture.treasure,
		"./assets/xpm/sprites/treasure.xpm");
}

void	load_sprites(t_data *data)
{
	load_ceiling_sprites(data);
	load_floor_sprites(data);
	load_lamps_sprites(data);
	load_treasure_sprites(data);
	get_sprite_texture(data);
}
