/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:39:39 by nmagamad          #+#    #+#             */
/*   Updated: 2025/03/21 11:52:38 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_error(char *print, char *file, t_parcing *s)
{
	ft_printf("%s", print);
	if (s->mapcpy)
		ft_freemap(file, s);
	return (1);
}

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
int		ft_check_EP(char *file, t_parcing *s, char c)
{
	int		j;
	int		count;

	count = 0;
	j = 0;
	while (j < map_count_line(file))
	{
		count += ft_strchr2(s->mapcpy[j], c);
		j++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int		ft_check_C(char *file, t_parcing *s)
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

int		ft_empty_check(char *file)
{
	char	*line;

	line = get_next_line(open(file, O_RDONLY));
	if (line == NULL)
		return (0);
	return (1);
}

int		dfs(int i, int j, t_parcing *s)
{
	
}

int		ft_floodfill(t_parcing *s)
{
	int		i;
	int		j;

	j = ft_get_j(s);
	i = ft_get_i(s);
	dfs(i, j, s);
	printf("%c",s->mapcpy[j][i]);
	return (1);
}

int	main(int ac, char **av)
{
	t_parcing	t;
	
	init_parcing(&t);
	if (ac != 2)
		return (1);
	if (!open(av[1], O_RDONLY))
		return (ft_error("Error\nle fichier n'est pas valide", av[1], &t));
	if (!ft_check_map_name(av[1]))
		return (ft_error("Error\nLe fichier n'est pas en .ber", av[1], &t));
	if (!ft_empty_check(av[1]))
		return (ft_error("Error\nLe fichier est vide", av[1], &t));
	if (!ft_map_copy(av[1], &t))
		return (ft_error("Error\nL'allocation de la map à échoué", av[1], &t));
	if (!ft_check_form(av[1], &t))
		return (ft_error("Error\nLa carte n'est pas rectangulaire", av[1], &t));
	if (!ft_check_walls(av[1], &t))
		return (ft_error("Error\nLa carte n'est pas entourée de murs", av[1], &t));
	if (!ft_check_EP(av[1], &t, 'P'))
		return (ft_error("Error\nIl n'y a pas de postition de depart sur la map, ou il y a un doublon", av[1], &t));
	if (!ft_check_EP(av[1], &t, 'E'))
		return (ft_error("Error\nIl n'y a pas de sortie sur la map, ou il y a un doublon de sortie", av[1], &t));
	if (!ft_check_C(av[1], &t))
		return (ft_error("Error\nIl n'y a pas d'item sur la map", av[1], &t));
	if (!ft_floodfill(&t))
		return (ft_error("Error\nLe chemin n'est pas bon", av[1], &t));
}
