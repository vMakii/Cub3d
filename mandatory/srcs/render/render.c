/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:44:33 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/05 11:00:43 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_frame(t_data *data)
{
	if (data->mlx.ptr == NULL)
		return (1);
	data->frame.image = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	data->frame.data = mlx_get_data_addr((void *)data->frame.image,
			&data->frame.bpp, &data->frame.size_line, &data->frame.endian);
	raycast(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->frame.image, 0,
		0);
	mlx_do_sync(data->mlx.ptr);
	mlx_destroy_image(data->mlx.ptr, data->frame.image);
	return (0);
}
