/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_forms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:34:21 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/23 19:47:34 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_rect(t_rect *rect, float size, int start_x, int start_y)
{
	rect->pos.x = start_x;
	rect->pos.y = start_y;
	rect->width = size;
	rect->height = size;
}

int	draw_rect(t_image *img, t_rect rect, int color)
{
	float	i;
	float	j;

	i = rect.pos.y;
	while (i < rect.pos.y + rect.height)
	{
		j = rect.pos.x;
		while (j < rect.pos.x + rect.width)
		{
			img_pix_put(img, j, i, color);
			j++;
		}
		i++;
	}
	return (0);
}

static void	init_line(t_coord_int *start, t_coord_int *end, t_coord_int *dist,
		t_coord_int *step)
{
	dist->x = abs(end->x - start->x);
	dist->y = abs(end->y - start->y);
	if (start->x < end->x)
		step->x = 1;
	else
		step->x = -1;
	if (start->y < end->y)
		step->y = 1;
	else
		step->y = -1;
}

//Bresenham's Line Algorithm
void	draw_line(t_image *img, t_coord_int start, t_coord_int end, int color)
{
	t_coord_int	dist;
	t_coord_int	step;
	int			err;
	int			err2;

	init_line(&start, &end, &dist, &step);
	err = dist.x - dist.y;
	while (1)
	{
		img_pix_put(img, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		err2 = err * 2;
		if (err2 > -dist.y)
		{
			err -= dist.y;
			start.x += step.x;
		}
		if (err2 < dist.x)
		{
			err += dist.x;
			start.y += step.y;
		}
	}
}

void	put_img_to_frame(t_image *frame, t_image *img, int x, int y)
{
	int	color;
	int	i;
	int	j;

	j = 0;
	while (j < img->height)
	{
		i = 0;
		while (i < img->width)
		{
			color = get_texture_color(img, i, j);
			img_pix_put(frame, x + i, y + j, color);
			i++;
		}
		j++;
	}
}
