/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:16:59 by gburtin           #+#    #+#             */
/*   Updated: 2025/08/14 19:17:37 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	insert_sorted(t_sprite **sorted, t_sprite *cur)
{
	t_sprite	*tmp;

	if (!*sorted || cur->distance > (*sorted)->distance)
	{
		cur->next = *sorted;
		*sorted = cur;
		return ;
	}
	tmp = *sorted;
	while (tmp->next && tmp->next->distance > cur->distance)
		tmp = tmp->next;
	cur->next = tmp->next;
	tmp->next = cur;
}

void	sort_sprites(t_sprite **lst)
{
	t_sprite	*sorted;
	t_sprite	*cur;
	t_sprite	*next;

	sorted = NULL;
	cur = *lst;
	while (cur)
	{
		next = cur->next;
		insert_sorted(&sorted, cur);
		cur = next;
	}
	*lst = sorted;
}
