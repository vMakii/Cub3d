/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_zombie.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:45:07 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/04 18:10:25 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	update_move(t_enemy *current, t_data *data)
{
	if (current->sprite->image == &data->texture.zombie_moving_0)
		current->sprite->image = &data->texture.zombie_moving_1;
	else if (current->sprite->image == &data->texture.zombie_moving_1)
		current->sprite->image = &data->texture.zombie_moving_2;
	else if (current->sprite->image == &data->texture.zombie_moving_2)
		current->sprite->image = &data->texture.zombie_moving_3;
	else if (current->sprite->image == &data->texture.zombie_moving_3)
		current->sprite->image = &data->texture.zombie_moving_4;
	else if (current->sprite->image == &data->texture.zombie_moving_4)
		current->sprite->image = &data->texture.zombie_moving_5;
	else if (current->sprite->image == &data->texture.zombie_moving_5)
		current->sprite->image = &data->texture.zombie_moving_6;
	else if (current->sprite->image == &data->texture.zombie_moving_6)
		current->sprite->image = &data->texture.zombie_moving_7;
	else
		current->sprite->image = &data->texture.zombie_moving_0;
}

void	update_zombie(t_enemy *current, t_data *data)
{
	if (current->state == ATTACK)
	{
		if (current->sprite->image == &data->texture.zombie_attack_0)
			current->sprite->image = &data->texture.zombie_attack_1;
		else if (current->sprite->image == &data->texture.zombie_attack_1)
			current->sprite->image = &data->texture.zombie_attack_2;
		else if (current->sprite->image == &data->texture.zombie_attack_2)
			current->sprite->image = &data->texture.zombie_attack_3;
		else if (current->sprite->image == &data->texture.zombie_attack_3)
			current->sprite->image = &data->texture.zombie_attack_4;
		else
			current->sprite->image = &data->texture.zombie_attack_0;
	}
	else if (current->state == MOVING)
		update_move(current, data);
	else if (current->state == DAMAGED)
		current->sprite->image = &data->texture.zombie_damaged;
	else
		current->sprite->image = &data->texture.zombie_dead;
}
