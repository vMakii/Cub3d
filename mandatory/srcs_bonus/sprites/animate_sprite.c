/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:21:15 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/20 11:10:34 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	update_lamps(t_sprite *current, t_data *data)
{
	if (g_frame_count % 5 == 0)
	{
		if (current->image == &data->texture.lamp_0)
			current->image = &data->texture.lamp_1;
		else if (current->image == &data->texture.lamp_1)
			current->image = &data->texture.lamp_2;
		else if (current->image == &data->texture.lamp_2)
			current->image = &data->texture.lamp_3;
		else
			current->image = &data->texture.lamp_0;
	}
}

void	update_animated_sprites(t_data *data)
{
	t_sprite	*current;

	current = data->sprite;
	while (current)
	{
		if (current->type == LAMP)
			update_lamps(current, data);
		current = current->next;
	}
}
