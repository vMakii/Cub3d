/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_enemies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:45:07 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/04 18:53:05 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	update_animated_enemies(t_data *data)
{
	t_enemy	*current;

	if (g_frame_count % 10 == 0)
	{
		current = data->enemy;
		while (current)
		{
			if (current->type == WEREWOLF)
				update_werewolf(current, data);
			else if (current->type == SKELETON)
			{
				if (current->state == ATTACK)
					current->sprite->scale = 225.0f;
				else
					current->sprite->scale = 180.0f;
				update_skeleton(current, data);
			}
			else if (current->type == ZOMBIE)
				update_zombie(current, data);
			if (current->state == DAMAGED)
				current->state = MOVING;
			current = current->next;
		}
	}
}
