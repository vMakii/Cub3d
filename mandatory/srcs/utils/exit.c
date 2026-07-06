/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:32:37 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/01 18:17:57 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_success(t_data *data)
{
	free_all(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	exit_failure(t_data *data, char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (errno)
	{
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
	}
	else
		ft_putendl_fd(str, STDERR_FILENO);
	free_all(data);
	exit(EXIT_FAILURE);
	return (-1);
}
