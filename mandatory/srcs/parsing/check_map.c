/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:15:17 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/07 16:26:19 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_map_elem(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != 'N' && data->map[i][j] != 'S'
				&& data->map[i][j] != 'E' && data->map[i][j] != 'W'
				&& data->map[i][j] != ' ')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	check_map_player(t_data *data)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				data->file.player_start[0] = i;
				data->file.player_start[1] = j;
				player++;
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		return (false);
	return (true);
}

static bool	floodfill(char **map, int x, int y)
{
	if (y > (int)ft_strlen(map[x]) || x < 0 || y < 0 || !map[x] || !map[x][y]
		|| map[x][y] == ' ')
		return (false);
	if (x < 0 || y < 0 || !map[x] || !map[x][y] || map[x][y] == '1')
		return (true);
	if (map[x][y] == '0' || map[x][y] == 'N' || map[x][y] == 'S'
		|| map[x][y] == 'E' || map[x][y] == 'W')
	{
		map[x][y] = '1';
		return (floodfill(map, x + 1, y) && floodfill(map, x - 1, y)
			&& floodfill(map, x, y + 1) && floodfill(map, x, y - 1));
	}
	return (true);
}

static bool	check_map_floodfill(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				if (!floodfill(map, i, j))
					return (ft_freetab(map), false);
			}
			j++;
		}
		i++;
	}
	return (ft_freetab(map), true);
}

bool	check_map(t_data *data)
{
	char	**cpy;

	if (!check_map_nl(data->file.str))
		exit_failure(data, "Newline in the map");
	if (!check_map_elem(data))
		exit_failure(data, "Invalid map element");
	if (!check_map_player(data))
		exit_failure(data, "Invalid player position or player missing");
	cpy = ft_tabcpy(data->map);
	if (!cpy)
		exit_failure(data, "Flood fill copy failed");
	if (!check_map_floodfill(cpy))
		exit_failure(data, "Map is not closed");
	return (true);
}
