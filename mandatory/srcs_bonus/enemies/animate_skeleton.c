/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_skeleton.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:45:07 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/04 18:08:07 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	update_attack(t_enemy *current, t_data *data)
{
	if (current->sprite->image == &data->texture.skeleton_attack_0)
		current->sprite->image = &data->texture.skeleton_attack_1;
	else if (current->sprite->image == &data->texture.skeleton_attack_1)
		current->sprite->image = &data->texture.skeleton_attack_2;
	else if (current->sprite->image == &data->texture.skeleton_attack_2)
		current->sprite->image = &data->texture.skeleton_attack_3;
	else if (current->sprite->image == &data->texture.skeleton_attack_3)
		current->sprite->image = &data->texture.skeleton_attack_4;
	else if (current->sprite->image == &data->texture.skeleton_attack_4)
		current->sprite->image = &data->texture.skeleton_attack_5;
	else
		current->sprite->image = &data->texture.skeleton_attack_0;
}

void	update_skeleton(t_enemy *current, t_data *data)
{
	if (current->state == ATTACK)
	{
		update_attack(current, data);
	}
	else if (current->state == MOVING)
	{
		if (current->sprite->image == &data->texture.skeleton_moving_0)
			current->sprite->image = &data->texture.skeleton_moving_1;
		else if (current->sprite->image == &data->texture.skeleton_moving_1)
			current->sprite->image = &data->texture.skeleton_moving_2;
		else if (current->sprite->image == &data->texture.skeleton_moving_2)
			current->sprite->image = &data->texture.skeleton_moving_3;
		else
			current->sprite->image = &data->texture.skeleton_moving_0;
	}
	else if (current->state == DAMAGED)
		current->sprite->image = &data->texture.skeleton_damaged;
	else
		current->sprite->image = &data->texture.skeleton_dead;
}
