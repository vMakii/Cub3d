/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:44:44 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/04 18:53:13 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_werewolf(t_enemy *enemy, t_data *data, t_sprite *sprite)
{
	enemy->type = WEREWOLF;
	enemy->sprite = sprite;
	enemy->state = MOVING;
	enemy->next = data->enemy;
	enemy->sprite->image = &data->texture.werewolf_moving_0;
	enemy->sprite->scale = 120.0f;
	enemy->speed = 0.03f;
	enemy->attack_cooldown = 10;
	enemy->hp = 100;
	enemy->attack_range = 0.9f;
	enemy->attack_damage = 5;
}

static void	init_zombie(t_enemy *enemy, t_data *data, t_sprite *sprite)
{
	enemy->type = ZOMBIE;
	enemy->sprite = sprite;
	enemy->state = MOVING;
	enemy->next = data->enemy;
	enemy->sprite->image = &data->texture.zombie_moving_0;
	enemy->sprite->scale = 180.0f;
	enemy->speed = 0.01f;
	enemy->attack_cooldown = 20;
	enemy->hp = 150;
	enemy->attack_range = 0.8f;
	enemy->attack_damage = 12;
}

static void	init_skeleton(t_enemy *enemy, t_data *data, t_sprite *sprite)
{
	enemy->type = SKELETON;
	enemy->sprite = sprite;
	enemy->state = MOVING;
	enemy->next = data->enemy;
	enemy->sprite->image = &data->texture.skeleton_moving_0;
	enemy->sprite->scale = 180.0f;
	enemy->speed = 0.02f;
	enemy->attack_cooldown = 30;
	enemy->hp = 80;
	enemy->attack_range = 0.7f;
	enemy->attack_damage = 8;
}

static void	randomize_enemy(t_enemy *enemy, t_data *data, t_sprite *sprite)
{
	int	r;

	r = rand();
	if (r % 3 == 0)
	{
		init_werewolf(enemy, data, sprite);
	}
	else if (r % 3 == 1)
	{
		init_zombie(enemy, data, sprite);
	}
	else
	{
		init_skeleton(enemy, data, sprite);
	}
}

void	init_enemy(t_data *data)
{
	t_sprite	*current;
	t_enemy		*new_enemy;

	current = data->sprite;
	while (current)
	{
		if (current->type == ENEMY)
		{
			new_enemy = gc_malloc(sizeof(t_enemy), &data->gc_list);
			if (!new_enemy)
				exit_failure(data, "Failed to allocate memory for enemy");
			randomize_enemy(new_enemy, data, current);
			new_enemy->next = data->enemy;
			data->enemy = new_enemy;
		}
		current = current->next;
	}
}
