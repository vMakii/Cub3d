/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:26:37 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/05 11:00:33 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	g_frame_count = 0;

int	loop(t_data *data)
{
	player_move(data);
	render_frame(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	parsing(argc, argv, &data);
	print_data_map(data);
	init(&data);
	mlx_hook(data.mlx.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.mlx.win, KeyRelease, KeyReleaseMask, &handle_keyrelease,
		&data);
	mlx_loop_hook(data.mlx.ptr, &loop, &data);
	mlx_loop(data.mlx.ptr);
	exit_success(&data);
	return (0);
}
