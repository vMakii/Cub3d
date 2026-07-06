/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:35:02 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/27 17:19:37 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_data_map(t_data data)
{
	printf("-------------\nDATA.MAP\n");
	printf("> NO: %s\n", data.texture.north_texture);
	printf("> SO: %s\n", data.texture.south_texture);
	printf("> WE: %s\n", data.texture.west_texture);
	printf("> EA: %s\n", data.texture.east_texture);
	printf("> F: %d, %d, %d\n", int_to_rgb(data.texture.floor_color)[0],
		int_to_rgb(data.texture.floor_color)[1],
		int_to_rgb(data.texture.floor_color)[2]);
	printf("> C: %d, %d, %d\n", int_to_rgb(data.texture.ceiling_color)[0],
		int_to_rgb(data.texture.ceiling_color)[1],
		int_to_rgb(data.texture.ceiling_color)[2]);
	printf("> Map:\n");
	ft_print_tab(data.map);
	printf("-------------\nDATA.FILE\n");
	ft_print_tab(data.file.tab);
	printf("-------------\n");
}
