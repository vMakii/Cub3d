/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:21:39 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/04 19:14:12 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	split_and_trim(t_data *data)
{
	int		i;
	char	*trim;

	data->file.tab = ft_split(data->file.str, '\n');
	if (!data->file.tab)
		return (false);
	i = 0;
	while (data->file.tab[i] && i < 6)
	{
		trim = ft_strtrim(data->file.tab[i], " ");
		if (!trim)
			return (false);
		free(data->file.tab[i]);
		data->file.tab[i] = ft_strdup(trim);
		if (!data->file.tab[i])
			return (free(trim), false);
		free(trim);
		i++;
	}
	gc_add_tab(data->file.tab, &data->gc_list);
	return (true);
}

static bool	has_only_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	read_loop(t_data *data, char *line, int fd)
{
	int	count;

	count = 0;
	while (line)
	{
		if (count < 6)
		{
			if (has_only_spaces(line) == false)
			{
				data->file.str = ft_strjoin_free(data->file.str, line);
				count++;
				if (!data->file.str)
					return (free(line), get_next_line(fd, 1), false);
			}
		}
		else
		{
			data->file.str = ft_strjoin_free(data->file.str, line);
			if (!data->file.str)
				return (free(line), get_next_line(fd, 1), false);
		}
		free(line);
		line = get_next_line(fd, 0);
	}
	return (true);
}

bool	read_file(char *filename, t_data *data)
{
	char	*line;
	int		fd;

	data->file.str = ft_strdup("");
	if (!data->file.str)
		return (false);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (free(data->file.str), false);
	line = get_next_line(fd, 0);
	if (!line)
		return (free(data->file.str), close(fd), false);
	if (!read_loop(data, line, fd))
		return (close(fd), free(data->file.str), false);
	gc_add_malloc(data->file.str, &data->gc_list);
	if (close(fd) == -1 || split_and_trim(data) == false)
		return (false);
	return (true);
}
