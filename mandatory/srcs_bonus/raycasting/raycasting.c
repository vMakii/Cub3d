/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:12:28 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/05 14:24:47 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Structure de données pour le raycasting:
	rayDir:			coordonnées du vecteur de direction du rayon
	cameraX:		position de la colonne à dessiner sur l'axe x du plan de 
						la camera (-1 gauche, à 1 droite, 0 étant le milieu)
	plane:			coordonnées du vecteur du plan de la camera, perpendiculaire
						au joueur, planeX défini le FOV
	deltaDist:		distance que le rayon doit parcourir pour traverser 
						1 case horizontale (X) / verticale (Y)
	step:			direction vers laquelle le rayon va bouger dans la grille
						sur l'axe x et sur l'axe y
	map:			coordonnées (int) de la case du joueur
	sideDist:		distances réelles depuis la position du joueur 
						jusqu’au premier mur
	side:			0 = mur vertical (X), 1 = mur horizontal (Y)
	perpWallDist:	distance au mur, perpendiculaire au plan de caméra
						pour éviter le fish eye
	wallHit:		coordonnées exactes du point de collision
						entre le rayon et le mur
	lineHeight:		hauteur de la colonne du mur, en nb pixel
	drawStart:		coordonnée y du haut du mur de la colonne à dessiner
	drawEnd:		coordonnée y du bas du mur de la colonne à dessiner
	wallX:			coordonnée x du mur touché, pour le calcul de la texture
	texNum:			numéro de la texture à utiliser pour le mur
	texX:			coordonnée x de la texture à utiliser pour le mur
	texY:			coordonnée y du pixel dans la colonne de la texture, 
						pour le calcul du pixel à dessiner
	texPos:			position verticale précise (float) actuelle dans la texture
						(après chaque texStep)
	texStep:		pas de déplacement dans la texture (ratio entre 
						la hauteur du mur et la hauteur de la texture)
		(< 1.0 → la texture est étirée, > 1.0 → la texture est compressée)
	texture:		tableau de textures pour les murs
	texWidth:		largeur de la texture
	texHeight:		hauteur de la texture
*/

#include "cub3d_bonus.h"

static void	dda_algorithm(t_data *data, t_ray *ray, int x)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = VERT_HIT;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = HORI_HIT;
		}
		if (data->map[ray->map.y][ray->map.x] == WALL)
			ray->hit = 1;
		else if (data->map[ray->map.y][ray->map.x] == DOOR)
		{
			if (!should_ray_pass_through_door(data, ray, x))
				break ;
		}
	}
}

void	perp_distance_to_wall(t_data *data, t_ray *ray)
{
	if (ray->side == VERT_HIT)
		ray->perp_wall_dist = ray->side_dist.x
			- ray->delta_dist.x;
	else
		ray->perp_wall_dist = ray->side_dist.y
			- ray->delta_dist.y;
	ray->wall_hit.x = data->player.pos.x + ray->perp_wall_dist
		* ray->ray_dir.x;
	ray->wall_hit.y = data->player.pos.y + ray->perp_wall_dist
		* ray->ray_dir.y;
}

void	get_wall_column(t_data *data, t_ray *ray)
{
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	if (ray->side == VERT_HIT)
		ray->wall_x = data->player.pos.y + ray->perp_wall_dist
			* ray->ray_dir.y;
	else
		ray->wall_x = data->player.pos.x + ray->perp_wall_dist
			* ray->ray_dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

static void	check_impact(t_data *data, t_ray *ray, int x)
{
	if (x == WIN_WIDTH / 2)
	{
		if (ray->perp_wall_dist < 1.0)
		{
			data->player.impact_zone = 1;
			data->player.impact_effect = BASE;
		}
		else
			data->player.impact_zone = 0;
	}
}

void	raycasting(t_data *data)
{
	int		x;
	t_ray	ray;

	x = 0;
	data->player.central_ray_distance = 0.0f;
	while (x < WIN_WIDTH)
	{
		init_ray(data, &ray, x);
		dda_algorithm(data, &ray, x);
		if (ray.hit == 1)
		{
			perp_distance_to_wall(data, &ray);
			if (data->player.central_ray_distance == 0.0f)
				update_central_ray(data, &ray, x);
			check_impact(data, &ray, x);
			get_wall_column(data, &ray);
			draw_wall(data, &ray, x);
			draw_double_wall(data, &ray, x);
		}
		draw_ceiling_column(data, ray, x, ray.draw_start);
		draw_floor_column(data, ray, x, ray.draw_end);
		data->z_buffer[x] = ray.perp_wall_dist;
		x++;
	}
}
