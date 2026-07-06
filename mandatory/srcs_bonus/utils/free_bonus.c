/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:05:34 by gburtin           #+#    #+#             */
/*   Updated: 2025/07/31 12:11:31 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	free_mlx(t_data *data)
{
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	if (data->mlx.ptr)
	{
		mlx_destroy_display(data->mlx.ptr);
		free(data->mlx.ptr);
	}
}

void	free_all(t_data *data)
{
	destroy_img(data);
	if (data->gc_list)
		gc_free(&data->gc_list);
	free_mlx(data);
}
