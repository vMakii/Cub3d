/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:10:09 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/25 16:49:48 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	get_sprite_distance(t_sprite *current, t_data *data)
{
	current->dir.x = data->player.pos.x - current->pos.x;
	current->dir.y = data->player.pos.y - current->pos.y;
	current->delta.x = current->pos.x - data->player.pos.x;
	current->delta.y = current->pos.y - data->player.pos.y;
	current->distance = current->delta.x * current->delta.x
		+ current->delta.y * current->delta.y;
}

static void	sprite_screen_coord(t_sprite *current, float inv_det,
	t_data *data)
{
	current->transformed_pos.x = inv_det * (data->player.dir.y
			* current->delta.x - data->player.dir.x * current->delta.y);
	current->transformed_pos.y = inv_det * (-data->player.plane.y
			* current->delta.x + data->player.plane.x * current->delta.y);
	current->screen_x = (int)((WIN_WIDTH / 2) * (1 + current->transformed_pos.x
				/ current->transformed_pos.y));
}

static void	get_size_sprite(t_sprite *current)
{
	float	aspect_ratio;

	if (current->type == ENEMY)
		aspect_ratio = current->scale;
	else if (current->type == RANDOM_C)
		aspect_ratio = 140.0f;
	else
		aspect_ratio = 150.0f;
	current->height = abs((int)(WIN_HEIGHT / current->transformed_pos.y
				* current->image->height / aspect_ratio));
	current->width = abs((int)(WIN_HEIGHT / current->transformed_pos.y
				* current->image->width / aspect_ratio));
	current->draw_start.x = -current->width / 2 + current->screen_x;
	current->draw_end.x = current->width / 2 + current->screen_x;
}

static void	get_sprite_position(t_sprite *current)
{
	if (current->type == RANDOM_C)
	{
		current->draw_start.y = WIN_HEIGHT / 2
			* (1 - 3 / current->transformed_pos.y);
		current->draw_end.y = current->draw_start.y + current->height;
	}
	else
	{
		current->draw_end.y = (int)(WIN_HEIGHT / 2
				* (1 + 1 / current->transformed_pos.y));
		current->draw_start.y = current->draw_end.y - current->height;
	}
	if (current->draw_start.y < 0)
	{
		current->tex_offset = -current->draw_start.y;
		current->draw_start.y = 0;
	}
	else
		current->tex_offset = 0;
	if (current->draw_end.y >= WIN_HEIGHT)
		current->draw_end.y = WIN_HEIGHT - 1;
}

void	render_sprites(t_data *data)
{
	t_sprite		*current;
	float			inv_det;

	update_animated_sprites(data);
	inv_det = 1.0f / (data->player.plane.x * data->player.dir.y
			- data->player.plane.y * data->player.dir.x);
	current = data->sprite;
	while (current)
	{
		current->is_seeing_player = false;
		get_sprite_distance(current, data);
		sprite_screen_coord(current, inv_det, data);
		get_size_sprite(current);
		get_sprite_position(current);
		current = current->next;
	}
	sort_sprites(&data->sprite);
	draw_sprites(data);
}
