/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:58:52 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/22 14:14:06 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	render_hud(t_data *data)
{
	render_health_bar(data);
	render_minimap(data);
	upscale_img(data, &data->texture.cursor, WIN_WIDTH / 2
		- (data->texture.cursor.width / 2) * UPSCALING, WIN_HEIGHT / 2
		- (data->texture.cursor.height / 2) * UPSCALING);
}
