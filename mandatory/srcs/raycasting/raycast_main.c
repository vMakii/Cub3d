/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:12:28 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/06 20:33:43 by gburtin          ###   ########.fr       */
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

#include "cub3d.h"

void	dda_algorithm(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->ray.side_dist.x < data->ray.side_dist.y)
		{
			data->ray.side_dist.x += data->ray.delta_dist.x;
			data->ray.map.x += data->ray.step.x;
			data->ray.side = VERT_HIT;
		}
		else
		{
			data->ray.side_dist.y += data->ray.delta_dist.y;
			data->ray.map.y += data->ray.step.y;
			data->ray.side = HORI_HIT;
		}
		if (data->map[data->ray.map.y][data->ray.map.x] == '1')
			hit = 1;
	}
}

void	perp_distance_to_wall(t_data *data)
{
	if (data->ray.side == VERT_HIT)
		data->ray.perp_wall_dist = data->ray.side_dist.x
			- data->ray.delta_dist.x;
	else
		data->ray.perp_wall_dist = data->ray.side_dist.y
			- data->ray.delta_dist.y;
	data->ray.wall_hit.x = data->player.pos.x + data->ray.perp_wall_dist
		* data->ray.ray_dir.x;
	data->ray.wall_hit.y = data->player.pos.y + data->ray.perp_wall_dist
		* data->ray.ray_dir.y;
}

void	get_wall_column(t_data *data)
{
	data->ray.line_height = (int)(WIN_HEIGHT / data->ray.perp_wall_dist);
	data->ray.draw_start = -data->ray.line_height / 2 + WIN_HEIGHT / 2;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + WIN_HEIGHT / 2;
	if (data->ray.draw_end >= WIN_HEIGHT)
		data->ray.draw_end = WIN_HEIGHT - 1;
	if (data->ray.side == VERT_HIT)
		data->ray.wall_x = data->player.pos.y + data->ray.perp_wall_dist
			* data->ray.ray_dir.y;
	else
		data->ray.wall_x = data->player.pos.x + data->ray.perp_wall_dist
			* data->ray.ray_dir.x;
	data->ray.wall_x -= floor(data->ray.wall_x);
}

void	raycast(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(data, x);
		dda_algorithm(data);
		perp_distance_to_wall(data);
		get_wall_column(data);
		draw_texture(data, x);
		x++;
	}
}
