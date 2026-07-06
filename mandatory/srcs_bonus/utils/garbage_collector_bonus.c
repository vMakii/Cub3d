/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:23:47 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/23 14:09:32 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	add_gb_to_back(t_garbage **gc_list, t_garbage *new_gb)
{
	t_garbage	*current;

	if (!gc_list || !new_gb)
		return ;
	if (!*gc_list)
	{
		*gc_list = new_gb;
		return ;
	}
	current = *gc_list;
	while (current->next)
		current = current->next;
	current->next = new_gb;
}

void	gc_free(t_garbage **gc_list)
{
	t_garbage	*current;
	t_garbage	*next;

	if (!gc_list || !*gc_list)
		return ;
	current = *gc_list;
	while (current)
	{
		next = current->next;
		free(current->alloc);
		free(current);
		current = next;
	}
	*gc_list = NULL;
}

void	*gc_add_malloc(void *ptr, t_garbage **gc_list)
{
	t_garbage	*new_gb;

	if (!ptr || !gc_list)
		return (ptr);
	new_gb = ft_calloc(1, sizeof(t_garbage));
	if (!new_gb)
	{
		perror("gc_add_malloc");
		return (ptr);
	}
	ft_bzero(new_gb, sizeof(t_garbage));
	new_gb->alloc = ptr;
	add_gb_to_back(gc_list, new_gb);
	return (ptr);
}

char	**gc_add_tab(char **tab, t_garbage **gc_list)
{
	int	i;

	if (!tab || !gc_list)
		return (tab);
	gc_add_malloc(tab, gc_list);
	i = 0;
	while (tab[i])
	{
		gc_add_malloc(tab[i], gc_list);
		i++;
	}
	return (tab);
}

void	*gc_malloc(size_t size, t_garbage **gc_list)
{
	t_garbage	*new_gb;
	void		*alloc;

	new_gb = ft_calloc(1, sizeof(t_garbage));
	alloc = malloc(size);
	if (!alloc || !new_gb)
	{
		free(alloc);
		free(new_gb);
		perror("gc_malloc");
		return (NULL);
	}
	ft_bzero(new_gb, sizeof(t_garbage));
	ft_bzero(alloc, size);
	new_gb->alloc = alloc;
	add_gb_to_back(gc_list, new_gb);
	return (alloc);
}
