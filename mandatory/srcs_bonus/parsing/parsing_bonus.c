/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:43:33 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/30 14:08:12 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
MAP VALIDE:
- La map doit être composée d’uniquement ces 6 caractères : 0 pour les espaces
vides, 1 pour les murs, et N,S,E ou W qui représentent la position de départ
du joueur et son orientation. --> parcourir map et compter position
- La map doit être fermée/entourée de murs, sinon le programme doit renvoyer
une erreur. --> flood fill
- Mis à part la description de la map, chaque type d’élément peut être séparée
par une ou plusieurs lignes vides. --> parcourir str
- La carte doit être parsée en accord avec ce qui est présenté dans le fichier.
Les espaces sont une partie valable de la carte, c’est à vous de les gérer
correctement. Vous devez pouvoir parser n’importe quelle sorte de carte,
tant qu’elle respecte les règles de carte. --> flood fill

ELEMENTS VALIDES:
//- Votre programme doit prendre en premier argument un fichier de description de
//scène avec pour extension .cub
//- La description de la carte sera toujours en dernier dans le fichier,
	le reste
// des éléments peut être dans n’importe quel ordre.
//- Sauf pour la map elle-même, les informations de chaque élément peuvent être
//séparées par un ou plusieurs espace(s).
//- Pour chaque élement, le premier caractère est l’identifiant (un ou deux
//caractères), suivi de toutes les informations spécifiques à l’élément dans
//un ordre strict NO, SO, WE, EA, F, C.
//	- Murs = one valid texture path
//	- Couleurs C/F = range [0,255] : 0, 255, 255
*/

#include "cub3d_bonus.h"

bool	check_filename(char *filename, char *ext)
{
	int	len;
	int	len_ext;

	if (!filename || !ext)
		return (false);
	len_ext = ft_strlen(ext);
	len = ft_strlen(filename);
	if (len >= len_ext)
	{
		if (ft_strncmp(&filename[len - len_ext], ext, len_ext) == 0)
			return (true);
	}
	return (false);
}

bool	get_map_name(char *filename, t_data *data)
{
	int	len;

	if (!filename || !data)
		return (false);
	len = ft_strlen(filename);
	if (len < 5 || ft_strncmp(&filename[len - 4], ".cub", 4) != 0)
		return (false);
	data->file.map_name = ft_substr(filename, 5, len - 9);
	if (!data->file.map_name)
		return (false);
	gc_add_malloc(data->file.map_name, &data->gc_list);
	return (true);
}

void	parsing(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		exit_failure(data, "Enter one map as argument");
	if (check_filename(argv[1], ".cub") == false)
		exit_failure(data, "Wrong filename");
	if (get_map_name(argv[1], data) == false)
		exit_failure(data, "Failed to get map name");
	if (read_file(argv[1], data) == false)
		exit_failure(data, "Reading file failed");
	if (check_data(data) == false)
		exit_failure(data, "Wrong textures description");
	if (get_data(data) == false)
		exit_failure(data, "Failure gathering data info");
	if (get_map(data) == false)
		exit_failure(data, "Map failure");
	if (check_map(data) == false)
		exit_failure(data, "Wrong map description");
	data->map[(int)data->player.pos.y][(int)data->player.pos.x] = '0';
}
