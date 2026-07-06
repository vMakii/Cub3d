/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combat_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:17:44 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/04 18:59:23 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	new_pose_is_not_in_wall(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || (data->map[y][(int)data->player.pos.x] == WALL
		&& data->map[(int)data->player.pos.y][x] == WALL))
		return (false);
	return (data->map[y][x] != WALL && data->map[y][x] != DOOR
		&& !is_door_blocking(data, x, y));
}

static void	hit_backstep(t_data *data, t_enemy *enemy, char character)
{
	float			backstep;
	t_coord_float	move;
	float			length;

	backstep = 0.5f;
	move.x = backstep * (data->player.pos.x - enemy->sprite->pos.x);
	move.y = backstep * (data->player.pos.y - enemy->sprite->pos.y);
	length = sqrtf(move.x * move.x + move.y * move.y);
	if (length > backstep)
	{
		move.x = (move.x / length) * backstep;
		move.y = (move.y / length) * backstep;
	}
	if (character == 'P' && new_pose_is_not_in_wall(data, data->player.pos.x
			+ move.x, data->player.pos.y + move.y))
	{
		data->player.pos.x += move.x;
		data->player.pos.y += move.y;
	}
	else if (character == 'E' && new_pose_is_not_in_wall(data,
			enemy->sprite->pos.x - move.x, enemy->sprite->pos.y - move.y))
	{
		enemy->sprite->pos.x -= move.x;
		enemy->sprite->pos.y -= move.y;
	}
}

static void	attack_enemy(t_data *data, t_enemy *enemy)
{
	enemy->attack_timer--;
	if (enemy->attack_timer <= 0)
	{
		enemy->attack_timer = 0;
		enemy->attack_hit = false;
		enemy->state = MOVING;
	}
	if (enemy->sprite->image == &data->texture.werewolf_attack_2
		|| enemy->sprite->image == &data->texture.skeleton_attack_4
		|| enemy->sprite->image == &data->texture.zombie_attack_3)
	{
		if (enemy->sprite->distance < enemy->attack_range
			&& data->player.hp > 0 && enemy->attack_hit == false)
		{
			enemy->attack_hit = true;
			data->player.is_hit++;
			data->player.hp -= enemy->attack_damage;
			if (data->player.hp < 0)
				data->player.hp = 0;
			enemy->attack_timer = enemy->attack_cooldown;
			hit_backstep(data, enemy, 'P');
		}
	}
}

void	combat_enemies(t_data *data)
{
	t_enemy	*enemy;

	if (data->player.is_hit > 0)
		data->player.is_hit = 0;
	enemy = data->enemy;
	while (enemy)
	{
		if (enemy->state != DEAD && enemy->state != DAMAGED)
		{
			if (enemy->sprite->distance < enemy->attack_range
				&& enemy->state != ATTACK)
			{
				enemy->state = ATTACK;
				enemy->attack_timer = enemy->attack_cooldown;
			}
			if (enemy->state == ATTACK)
				attack_enemy(data, enemy);
		}
		enemy = enemy->next;
	}
}

void	enemy_take_damage(t_data *data, t_enemy *enemy)
{
	if (enemy && enemy->state != DEAD)
	{
		enemy->hp -= data->player.weapon.damage;
		if (enemy->hp <= 0)
		{
			enemy->hp = 0;
			enemy->state = DEAD;
			if (enemy->type == WEREWOLF)
				enemy->sprite->image = &data->texture.werewolf_dead;
			else if (enemy->type == SKELETON)
				enemy->sprite->image = &data->texture.skeleton_dead;
			else if (enemy->type == ZOMBIE)
				enemy->sprite->image = &data->texture.zombie_dead;
		}
		else
			enemy->state = DAMAGED;
		hit_backstep(data, enemy, 'E');
	}
}
