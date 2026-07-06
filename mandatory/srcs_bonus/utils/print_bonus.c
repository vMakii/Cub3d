/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:35:02 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/22 11:00:19 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	print_data_map(t_data data)
{
	printf("-------------\nDATA.MAP\n");
	printf("> NO: %s\n", data.file.north_texture);
	printf("> SO: %s\n", data.file.south_texture);
	printf("> WE: %s\n", data.file.west_texture);
	printf("> EA: %s\n", data.file.east_texture);
	printf("> F: %d, %d, %d\n", int_to_rgb(data.file.floor_color)[0],
		int_to_rgb(data.file.floor_color)[1],
		int_to_rgb(data.file.floor_color)[2]);
	printf("> C: %d, %d, %d\n", int_to_rgb(data.file.ceiling_color)[0],
		int_to_rgb(data.file.ceiling_color)[1],
		int_to_rgb(data.file.ceiling_color)[2]);
	printf("> Map:\n");
	ft_print_tab(data.map);
	printf("-------------\n");
}

void	print_sprites(t_data *data)
{
	t_sprite	*current;

	if (g_frame_count % 60 != 0)
		return ;
	current = data->sprite;
	while (current)
	{
		printf("Sprite at (%.1f, %.1f) of type %c\n", current->pos.x,
			current->pos.y, current->type);
		current = current->next;
	}
}

void	print_enemies(t_data *data)
{
	t_enemy	*current;

	if (g_frame_count % 60 != 0)
		return ;
	current = data->enemy;
	while (current)
	{
		printf("Enemy at (%.1f, %.1f) of type %d\n", current->sprite->pos.x,
			current->sprite->pos.y, current->type);
		printf("image: %p, scale: %.2f\n", current->sprite->image,
			current->sprite->scale);
		printf("state: %d, hp: %d, attack_range: %.2f, attack_cooldown: %d\n",
			current->state, current->hp, current->attack_range,
			current->attack_cooldown);
		current = current->next;
	}
}
