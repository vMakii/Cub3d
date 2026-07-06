/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_effects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:49:48 by mivogel           #+#    #+#             */
/*   Updated: 2025/08/22 12:15:19 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	load_impact(t_data *data)
{
	load_img(data, &data->texture.impact_0, "./assets/xpm/impact/impact_0.xpm");
	load_img(data, &data->texture.impact_1, "./assets/xpm/impact/impact_1.xpm");
	load_img(data, &data->texture.impact_2, "./assets/xpm/impact/impact_2.xpm");
	load_img(data, &data->texture.impact_3, "./assets/xpm/impact/impact_3.xpm");
	load_img(data, &data->texture.impact_4, "./assets/xpm/impact/impact_4.xpm");
}

static void	load_blood(t_data *data)
{
	load_img(data, &data->texture.blood_0, "./assets/xpm/impact/blood_0.xpm");
	load_img(data, &data->texture.blood_1, "./assets/xpm/impact/blood_1.xpm");
	load_img(data, &data->texture.blood_2, "./assets/xpm/impact/blood_2.xpm");
	load_img(data, &data->texture.blood_3, "./assets/xpm/impact/blood_3.xpm");
	load_img(data, &data->texture.blood_4, "./assets/xpm/impact/blood_4.xpm");
}

static void	load_hit_screen(t_data *data)
{
	load_img(data, &data->texture.hit, "./assets/xpm/screen/hit.xpm");
}

void	load_effects(t_data *data)
{
	load_impact(data);
	load_hit_screen(data);
	load_blood(data);
}
