/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:44:24 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/03 12:58:14 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	reset_magick_state(t_data *data)
{
	data->player.magick.casting = false;
	data->player.magick.casted = false;
	data->player.magick.cd = false;
	data->player.magick.hand_left = &data->texture.player_cast_0_l;
	data->player.magick.hand_right = &data->texture.player_cast_0_r;
	data->player.magick.spell = &data->texture.player_magick_9;
}

void	update_player_cast(t_data *data)
{
	static float	last_time;
	float			current_time;
	float			diff;

	current_time = get_time();
	diff = current_time - last_time;
	if (!last_time)
		last_time = current_time;
	else if (diff > 0.6)
	{
		reset_magick_state(data);
		last_time = current_time;
	}
	else if (!data->player.magick.casted || !data->player.magick.casting)
		data->player.magick.cd = true;
}

static void	handle_mov(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_Up)
		data->keys.key_w = 1;
	else if (keysym == XK_s || keysym == XK_Down)
		data->keys.key_s = 1;
	else if (keysym == XK_a)
		data->keys.key_a = 1;
	else if (keysym == XK_d)
		data->keys.key_d = 1;
	else if (keysym == XK_Left)
		data->keys.key_left = 1;
	else if (keysym == XK_Right)
		data->keys.key_right = 1;
	else if (keysym == XK_Up)
		data->keys.key_up = 1;
	else if (keysym == XK_Down)
		data->keys.key_down = 1;
	else if (keysym == XK_e)
	{
		data->keys.key_e = 1;
		update_player_cast(data);
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		exit_success(data);
	handle_mov(keysym, data);
	if (keysym == XK_Shift_L && data->player.action != RUNNING)
		data->player.action = RUNNING;
	if (keysym == XK_space && data->player.action != ATTACKING
		&& data->player.action != RUNNING)
		data->player.action = ATTACKING;
	if (keysym == XK_e && data->player.action == CASTING)
		data->player.action = IDLE;
	else if (keysym == XK_e && data->player.action != CASTING)
		data->player.action = CASTING;
	if (keysym == XK_Control_L)
		change_weapons(data);
	if (keysym == XK_f)
		interact_with_door(data);
	return (0);
}
