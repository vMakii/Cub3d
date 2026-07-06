/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyrelease.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:31:52 by mivogel           #+#    #+#             */
/*   Updated: 2025/08/06 11:30:07 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		exit_success(data);
	if (keysym == XK_w || keysym == XK_Up)
		data->keys.key_w = 0;
	else if (keysym == XK_s || keysym == XK_Down)
		data->keys.key_s = 0;
	else if (keysym == XK_a)
		data->keys.key_a = 0;
	else if (keysym == XK_d)
		data->keys.key_d = 0;
	else if (keysym == XK_Left)
		data->keys.key_left = 0;
	else if (keysym == XK_Right)
		data->keys.key_right = 0;
	return (0);
}
