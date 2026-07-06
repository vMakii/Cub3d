/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:02:16 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/25 11:33:46 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	add_list_sprite(t_sprite **lst, t_sprite *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	*lst = new;
}

static t_sprite	*add_sprite(t_data *data, int x, int y, char type)
{
	t_sprite	*new_sprite;

	new_sprite = gc_malloc(sizeof(t_sprite), &data->gc_list);
	if (!new_sprite)
		exit_failure(data, "Failed to allocate memory for sprite");
	new_sprite->pos.x = x + 0.5;
	new_sprite->pos.y = y + 0.5;
	new_sprite->dir.x = data->player.pos.x - new_sprite->pos.x;
	new_sprite->dir.y = data->player.pos.y - new_sprite->pos.y;
	new_sprite->type = type;
	new_sprite->distance = 999.0f;
	if (new_sprite->type == RANDOM_C)
		new_sprite->offset = 1.0f;
	else
		new_sprite->offset = 0.0f;
	new_sprite->next = data->sprite;
	add_list_sprite(&data->sprite, new_sprite);
	return (new_sprite);
}

void	get_sprites_from_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == RANDOM_C)
				data->sprite = add_sprite(data, x, y, RANDOM_C);
			else if (data->map[y][x] == RANDOM_F)
				data->sprite = add_sprite(data, x, y, RANDOM_F);
			else if (data->map[y][x] == TREASURE)
				data->sprite = add_sprite(data, x, y, TREASURE);
			else if (data->map[y][x] == LAMP)
				data->sprite = add_sprite(data, x, y, LAMP);
			else if (data->map[y][x] == ENEMY)
				data->sprite = add_sprite(data, x, y, ENEMY);
			x++;
		}
		y++;
	}
}

static void	randomize_texture(t_sprite *sprite, t_data *data, int max,
		int is_ceiling)
{
	int	r;

	r = rand() % max;
	if (is_ceiling)
		sprite->image = &data->texture.sprites_ceiling[r];
	else
		sprite->image = &data->texture.sprites_floor[r];
}

void	get_sprite_texture(t_data *data)
{
	t_sprite	*current;

	current = data->sprite;
	while (current)
	{
		if (current->type == RANDOM_C)
			randomize_texture(current, data, NB_SPRITES_C, 1);
		else if (current->type == RANDOM_F)
			randomize_texture(current, data, NB_SPRITES_F, 0);
		else if (current->type == TREASURE)
			current->image = &data->texture.treasure;
		else if (current->type == LAMP)
			current->image = &data->texture.lamp_0;
		current = current->next;
	}
	init_enemy(data);
}
