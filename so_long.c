/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magamadov <magamadov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:39:39 by nmagamad          #+#    #+#             */
/*   Updated: 2025/03/20 08:57:00 by magamadov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_name(char *map_name)
{
	int	i;
	
	i = 0;
	while(map_name[i])
	{
		i++;
	}
	if (i > 4 && map_name[i - 4] == '.' && map_name[i - 3] == 'b' && map_name[i - 2] == 'e'
		&& map_name[i - 1] == 'r')
		return (1);
	return (0);
}

int		ft_check_form(char *file, t_parcing *s)
{
	int		i;

	i = 0;
	
	s->y_len1 = map_count_line(file);
	while (s->j < s->y_len1)
	{
		if (s->mapcpy[s->j][ft_strlenn(s->mapcpy[s->j]) - 1] == '\n')
		{
			s->mapcpy[s->j][ft_strlenn(s->mapcpy[s->j]) - 1] = '\0';
		}
		s->j++;
	}
	s->first_line_len = ft_strlenn(s->mapcpy[0]);
	while (i < s->y_len1)
	{
		s->line_comp = ft_strlenn(s->mapcpy[i]);
		if (s->first_line_len != s->line_comp || s->first_line_len == s->y_len1)
			return (0);
		s->line_comp = 0;
		i++;
	}
	return (1);
}

int		ft_check_walls(char *file, t_parcing *s)
{
	int		j;

	j = 0;
	if (!first_last_walls(s->mapcpy[0]) ||
	!first_last_walls(s->mapcpy[map_count_line(file) - 1]))
			return (0);
	while(j < map_count_line(file))
	{
		if (s->mapcpy[j][0] != '1'
			|| s->mapcpy[j][ft_strlenn(s->mapcpy[j]) - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int		first_last_walls(char *str)
{
	int		i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_parcing	t;
	
	init_parcing(&t);
	if (ac != 2)
		return (1);
	if (!ft_check_map_name(av[1]))
	{
		ft_printf("Error\nLe fichier n'est pas en .ber");
		return (1);
	}
	if (!ft_map_copy(av[1], &t))
	{
		ft_printf("Error\nL'allocation de la map à échoué");
		return (1);
	}
	if (!ft_check_form(av[1], &t))
	{
		ft_printf("Error\nLa carte n'est pas rectangulaire");
		return (1);
	}
	if (!ft_check_walls(av[1], &t))
	{
		ft_printf("Error\nLa carte n'est pas entourée de murs");
		return (1);
	}
	if (!ft_check_chars(av[1], &t))
	{
		 
	}
}
