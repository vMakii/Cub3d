/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:38:30 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/04 19:28:34 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	render_starting_screen(t_data *data)
{
	if (data->mlx.ptr == NULL)
		return (1);
	data->frame.image = mlx_new_image(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	data->frame.data = mlx_get_data_addr((void *)data->frame.image,
			&data->frame.bpp, &data->frame.size_line, &data->frame.endian);
	if (data->starting_screen.state == START)
		upscale_img(data, &data->texture.starting_screen_0, 0, 0);
	else if (data->starting_screen.state == EXIT)
		upscale_img(data, &data->texture.starting_screen_1, 0, 0);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->frame.image, 0,
		0);
	mlx_do_sync(data->mlx.ptr);
	mlx_destroy_image(data->mlx.ptr, data->frame.image);
	return (0);
}

int	loop_starting_screen(t_data *data)
{
	render_starting_screen(data);
	if (data->starting_screen.start)
	{
		destroy_screens(data);
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
		return (1);
	}
	return (0);
}

int	handle_keypress_starting(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		exit_success(data);
	if (keysym == XK_Return && data->starting_screen.state == START)
		data->starting_screen.start = true;
	if (keysym == XK_Return && data->starting_screen.state == EXIT)
		exit_success(data);
	if (keysym == XK_Down)
		data->starting_screen.state = EXIT;
	if (keysym == XK_Up)
		data->starting_screen.state = START;
	return (0);
}

void	mini_init(t_data *data)
{
	data->mlx.ptr = mlx_init();
	if (!data->mlx.ptr)
		exit_failure(data, "Error\nMLX couldn't be initiated\n");
	data->mlx.win = mlx_new_window(data->mlx.ptr, WIN_WIDTH, WIN_HEIGHT,
			"cub3d");
	mlx_hook(data->mlx.win, DestroyNotify, StructureNotifyMask, &exit_success,
		data);
	load_screens(data);
}

void	starting_screen(t_data *data)
{
	mini_init(data);
	data->starting_screen.state = START;
	data->starting_screen.start = false;
	mlx_loop_hook(data->mlx.ptr, &loop_starting_screen, data);
	mlx_hook(data->mlx.win, KeyPress, KeyPressMask, &handle_keypress_starting,
		data);
	mlx_loop(data->mlx.ptr);
	mlx_destroy_display(data->mlx.ptr);
	free(data->mlx.ptr);
}
