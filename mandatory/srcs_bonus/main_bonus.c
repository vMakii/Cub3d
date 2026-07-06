/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:26:37 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/03 14:21:34 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		g_frame_count = 0;

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

static void	init(t_data *data)
{
	srand(time(NULL));
	init_mlx(data);
	init_player(data);
	init_img(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	parsing(argc, argv, &data);
	starting_screen(&data);
	init(&data);
	data.time.oldtime = get_time();
	mlx_hook(data.mlx.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.mlx.win, KeyRelease, KeyReleaseMask, &handle_keyrelease,
		&data);
	mlx_loop_hook(data.mlx.ptr, &loop, &data);
	mlx_mouse_hook(data.mlx.win, &handle_mouse, &data);
	mlx_loop(data.mlx.ptr);
	exit_success(&data);
	return (0);
}
