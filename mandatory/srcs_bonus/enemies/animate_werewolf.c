/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_enemies copy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:45:07 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/04 18:06:18 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	update_werewolf(t_enemy *current, t_data *data)
{
	if (current->state == ATTACK)
	{
		if (current->sprite->image == &data->texture.werewolf_attack_0)
			current->sprite->image = &data->texture.werewolf_attack_1;
		else if (current->sprite->image == &data->texture.werewolf_attack_1)
			current->sprite->image = &data->texture.werewolf_attack_2;
		else
			current->sprite->image = &data->texture.werewolf_attack_0;
	}
	else if (current->state == MOVING)
	{
		if (current->sprite->image == &data->texture.werewolf_moving_0)
			current->sprite->image = &data->texture.werewolf_moving_1;
		else if (current->sprite->image == &data->texture.werewolf_moving_1)
			current->sprite->image = &data->texture.werewolf_moving_2;
		else if (current->sprite->image == &data->texture.werewolf_moving_2)
			current->sprite->image = &data->texture.werewolf_moving_3;
		else
			current->sprite->image = &data->texture.werewolf_moving_0;
	}
	else if (current->state == DAMAGED)
		current->sprite->image = &data->texture.werewolf_damaged;
	else
		current->sprite->image = &data->texture.werewolf_dead;
}
