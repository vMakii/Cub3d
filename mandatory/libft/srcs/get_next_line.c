/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:02:34 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/22 12:10:53 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read(int fd, char *buffer)
{
	char	*tmp;
	int		i;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp || !buffer)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1)
		{
			free(tmp);
			free(buffer);
			return (NULL);
		}
		tmp[i] = 0;
		buffer = ft_strjoin_free(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

static char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	next = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(*buffer));
	if (!next)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	free(buffer);
	return (next);
}

char	*get_next_line(int fd, int n)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (n == 1)
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	if (!line && buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
//
// #include <fcntl.h>
// #include <stdio.h>
//
// int	main(int ac, char **av)
// {
// 	int		i;
// 	int		fd;
// 	char	*line;
//
// 	(void)ac;
// 	fd = open(av[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	i = 0;
// 	while (i < 2)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	if (line)
// 		free(line);
// 	close(fd);
// 	return (0);
// }