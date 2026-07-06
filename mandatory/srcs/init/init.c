/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:27:29 by mivogel           #+#    #+#             */
/*   Updated: 2025/08/06 11:14:33 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx(t_data *data)
{
	data->mlx.ptr = mlx_init();
	if (!data->mlx.ptr)
		exit_failure(data, "Error\nMLX couldn't be initiated\n");
	data->mlx.win = mlx_new_window(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT,
			"cub3d");
	mlx_hook(data->mlx.win, DestroyNotify, StructureNotifyMask, &exit_success,
		data);
}

void	init(t_data *data)
{
	init_mlx(data);
	init_img(data);
}
