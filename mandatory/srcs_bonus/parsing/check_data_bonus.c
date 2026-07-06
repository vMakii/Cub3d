/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:07:59 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/05 14:18:33 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	check_order(char **tab)
{
	int	len;
	int	i;

	len = 0;
	while (tab[len])
		len++;
	i = 0;
	while (tab[len - 1][i])
	{
		if (tab[len - 1][i] != '1' && tab[len - 1][i] != ' ' && tab[len
			- 1][i] != '0')
			return (false);
		i++;
	}
	return (true);
}

// static bool	check_number_of_info_lines(char **tab)
// {
// 	int	i;
// 	int	j;
// 	int	count;

// 	count = 0;
// 	i = 0;
// 	while (tab[i])
// 	{
// 		j = 0;
// 		while (tab[i][j])
// 		{
// 			if (!is_valid_map_char(tab[i][j]) && tab[i][j] != '\n')
// 			{
// 				count++;
// 				break ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (count == 6)
// 		return (true);
// 	return (false);
// }

bool	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ' || c == 'D' || c == 'C' || c == 'F' || c == 'T' || c == 'M'
		|| c == 'L');
}

// if (check_number_of_info_lines(data->file.tab) == false)
// 	exit_failure(data, "Too much or not enough information lines");
bool	check_data(t_data *data)
{
	if (check_order(data->file.tab) == false)
		exit_failure(data, "Map is not at the end of the file");
	if (check_texture(data->file.tab, "NO") == false)
		exit_failure(data, "Missing or invalid NO texture");
	if (check_texture(data->file.tab, "SO") == false)
		exit_failure(data, "Missing or invalid SO texture");
	if (check_texture(data->file.tab, "WE") == false)
		exit_failure(data, "Missing or invalid WE texture");
	if (check_texture(data->file.tab, "EA") == false)
		exit_failure(data, "Missing or invalid EA texture");
	if (check_colors(data->file.tab, "F") == false)
		exit_failure(data, "Missing or invalid F color");
	if (check_colors(data->file.tab, "C") == false)
		exit_failure(data, "Missing or invalid C color");
	return (true);
}
