/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:22:56 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/26 11:29:55 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	combat_player(t_data *data)
{
	t_enemy	*enemy;

	enemy = data->enemy;
	if (data->player.action == ATTACKING)
	{
		while (enemy)
		{
			if (enemy->state != DEAD
				&& enemy->sprite->distance < data->player.weapon.range)
			{
				check_impact_on_enemy(data, enemy);
				if (data->player.impact && enemy->state != DAMAGED)
					enemy_take_damage(data, enemy);
			}
			enemy = enemy->next;
		}
	}
}
