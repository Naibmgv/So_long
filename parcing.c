/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:39:39 by nmagamad          #+#    #+#             */
/*   Updated: 2025/04/08 18:33:39 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_p(char *file, t_parcing *s)
{
	int		j;
	int		count;

	count = 0;
	j = 0;
	while (j < map_count_line(file))
	{
		count += ft_strchr2(s->mapcpy[j], 'P');
		j++;
	}
	if (count < 1)
		return (ft_error("Error\nLa carte ne contient pas de joueur", s));
	if (count > 1)
		return (ft_error("Error\nLa carte contient trop de joueurs", s));
	return (1);
}

int	ft_check_e(char *file, t_parcing *s)
{
	int		j;
	int		count;

	count = 0;
	j = 0;
	while (j < map_count_line(file))
	{
		count += ft_strchr2(s->mapcpy[j], 'E');
		j++;
	}
	if (count < 1)
		return (ft_error("Error\nLa carte ne contient pas de sortie", s));
	if (count > 1)
		return (ft_error("Error\nLa carte contient trop de sorties", s));
	return (1);
}

int	ft_check_c(char *file, t_parcing *s)
{
	int		j;
	int		count;

	count = 0;
	j = 0;
	while (j < map_count_line(file))
	{
		count += ft_strchr2(s->mapcpy[j], 'C');
		j++;
	}
	if (count < 1)
		return (0);
	return (count);
}

void	flood_fill(int x, int y, t_parcing *s)
{
	if (s->mapcpy2[y][x] == 'E')
		s->count_exit++;
	if (s->mapcpy2[y][x] == 'C')
		s->count_collectibles++;
	if (x < 0 || y < 0 || y >= s->y_len3 || x >= s->map_len2
		|| ft_strchrr("1VE", s->mapcpy2[y][x]))
		return ;
	s->mapcpy2[y][x] = 'V';
	flood_fill(x + 1, y, s);
	flood_fill(x - 1, y, s);
	flood_fill(x, y + 1, s);
	flood_fill(x, y - 1, s);
}

int	parse(t_parcing *s)
{
	s->mapcpy2 = ft_dup_tab(s->mapcpy);
	s->y_len3 = ft_tab_len(s->mapcpy2);
	s->map_len2 = ft_strlenn(s->mapcpy2[0]);
	flood_fill(ft_get_i(s), ft_get_j(s), s);
	if (s->count_collectibles != ft_check_c(s->file, s))
		return (ft_error("Error\nEatables are not reachable", s));
	if (!s->count_exit)
		return (ft_error("Error\nLa sortie n'est pas atteignalble", s));
	free_map(s->mapcpy2);
	return (0);
}
