/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upscale_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:34:31 by mivogel           #+#    #+#             */
/*   Updated: 2025/08/21 10:34:28 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	mlx_get_pixel(void *img, int x, int y)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;

	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	return (*(int *)(data + (y * size_line + x * (bpp / 8))));
}

static void	mlx_put_pixel(void *img, int x, int y, int color)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;

	if (color == (int)0xFF000000)
		return ;
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	*(int *)(data + (y * size_line + x * (bpp / 8))) = color;
}

static void	upscale_img_loop(t_image *frame, t_image *sprite, int dest_x,
		int dest_y)
{
	int	x;
	int	y;
	int	new_x;
	int	new_y;
	int	pixel_color;

	y = -1;
	while (++y < sprite->height)
	{
		x = -1;
		while (++x < sprite->width)
		{
			pixel_color = mlx_get_pixel(sprite->image, x, y);
			new_y = -1;
			while (++new_y < UPSCALING)
			{
				new_x = -1;
				while (++new_x < UPSCALING)
					mlx_put_pixel(frame->image, dest_x + x * UPSCALING + new_x,
						dest_y + y * UPSCALING + new_y, pixel_color);
			}
		}
	}
}

void	upscale_img(t_data *data, t_image *sprite, int dest_x,
		int dest_y)
{
	upscale_img_loop(&data->frame, sprite, dest_x, dest_y);
}

	// t_coord_int pos;

	// pos.x = dest_x;
	// pos.y = dest_y;
	// upscale_img_loop(&data->frame, sprite, &pos);
