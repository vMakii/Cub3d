/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:50:22 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/04 19:00:21 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_impact_on_enemy(t_data *data, t_enemy *enemy)
{
	if (enemy->sprite->distance < 1.0 && enemy->state != DEAD
		&& is_on_screen(enemy))
	{
		data->player.impact_zone = 1;
		if (enemy->type == SKELETON)
			data->player.impact_effect = BASE;
		else
			data->player.impact_effect = BLOOD;
	}
	else
		data->player.impact_zone = 0;
}

bool	is_on_screen(t_enemy *enemy)
{
	if (enemy->sprite->transformed_pos.y > 0 && enemy->sprite->screen_x >= 0
		&& enemy->sprite->screen_x < WIN_WIDTH)
		return (true);
	return (false);
}

static bool	is_in_front_of_player(t_enemy *enemy, t_data *data)
{
	if ((data->keys.key_w || data->keys.key_up) && is_on_screen(enemy))
		return (true);
	if ((data->keys.key_s || data->keys.key_down) && !is_on_screen(enemy))
		return (true);
	return (false);
}

bool	is_enemy_blocking(t_data *data, int map_x, int map_y)
{
	t_enemy	*enemy;

	enemy = data->enemy;
	while (enemy)
	{
		if ((int)(enemy->sprite->pos.x) == map_x
			&& (int)(enemy->sprite->pos.y) == map_y)
		{
			if (enemy->state == DEAD)
				return (false);
			else if (is_in_front_of_player(enemy, data)
				&& enemy->sprite->distance < 0.2f)
			{
				return (true);
			}
		}
		enemy = enemy->next;
	}
	return (false);
}
