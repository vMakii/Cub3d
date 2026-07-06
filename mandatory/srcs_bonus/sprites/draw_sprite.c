/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:19:27 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/03 12:48:57 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_column(t_data *data, t_sprite *current, int stripe)
{
	int	y;
	int	color;

	y = current->draw_start.y;
	while (y < current->draw_end.y)
	{
		current->d = (y - current->draw_start.y + current->tex_offset);
		current->tex_y = (current->d * current->image->height)
			/ current->height;
		color = get_texture_color(current->image, current->tex_x,
				current->tex_y);
		if (!is_pixel_transparent(color))
		{
			apply_shadow(current->distance, &color, 'S');
			img_pix_put(&data->frame, stripe, y, color);
		}
		y++;
	}
	if (stripe == current->screen_x)
		current->is_seeing_player = true;
}

void	draw_sprites(t_data *data)
{
	t_sprite	*current;
	int			stripe;

	current = data->sprite;
	while (current)
	{
		if (current->transformed_pos.y >= 0.1f)
		{
			stripe = current->draw_start.x;
			while (stripe < current->draw_end.x)
			{
				current->tex_x = (int)(256 * (stripe - current->draw_start.x)
						* current->image->width / current->width) / 256;
				if (current->transformed_pos.y > 0 && stripe >= 0
					&& stripe < WIN_WIDTH
					&& current->transformed_pos.y < data->z_buffer[stripe])
				{
					draw_column(data, current, stripe);
				}
				stripe++;
			}
		}
		current = current->next;
	}
}
