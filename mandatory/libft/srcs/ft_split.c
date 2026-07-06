/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:08:24 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/22 12:07:37 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freesplit(char **tab, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_count_word(char const *s, char sep)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == sep)
			++s;
		if (*s)
			++i;
		while (*s && *s != sep)
			++s;
	}
	return (i);
}

static int	ft_set(char **tab, char const *s, char sep)
{
	const char	*tmp;
	int			i;

	i = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		tmp = s;
		while (*s && *s != sep)
			s++;
		if (s > tmp)
		{
			tab[i] = ft_substr(tmp, 0, s - tmp);
			if (!tab[i])
			{
				ft_freesplit(tab, i);
				return (0);
			}
			i++;
		}
	}
	tab[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_count_word(s, c);
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	if (!ft_set(tab, s, c))
		return (NULL);
	return (tab);
}
