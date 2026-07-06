/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:07:46 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/07 16:42:00 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
