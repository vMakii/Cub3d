/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:07:46 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/15 20:06:14 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	rgb_to_int(u_int8_t r, u_int8_t g, u_int8_t b)
{
	return ((r << 16) | (g << 8) | b);
}

int	*int_to_rgb(int color)
{
	static int	rgb[3];

	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = color & 0xFF;
	return (rgb);
}

bool	is_pixel_transparent(unsigned int color)
{
	return (color == 0xFF000000);
}

void	apply_shadow(float distance, int *color, char type)
{
	int		*rgb;
	float	distance_factor;

	if (type == 'W')
		distance_factor = 1.0f - (distance / 12.0f);
	else if (type == 'S')
		distance_factor = 1.0f - (distance / 90.0f);
	else
		distance_factor = 1.0f - (distance / 20.0f);
	if (distance_factor < 0.0f)
		distance_factor = 0.0f;
	if (distance_factor > 1.0f)
		distance_factor = 1.0f;
	rgb = int_to_rgb(*color);
	rgb[0] = (int)(rgb[0] * distance_factor);
	rgb[1] = (int)(rgb[1] * distance_factor);
	rgb[2] = (int)(rgb[2] * distance_factor);
	*color = rgb_to_int(rgb[0], rgb[1], rgb[2]);
}
