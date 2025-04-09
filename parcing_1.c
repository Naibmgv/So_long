/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:21:40 by nmagamad          #+#    #+#             */
/*   Updated: 2025/04/08 18:26:27 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *print, t_parcing *s)
{
	ft_printf("%s", print);
	if (s->mapcpy)
		free_map(s->mapcpy);
	if (s->mapcpy2)
		free_map(s->mapcpy2);
	exit (0);
	return (1);
}

int	ft_check_map_name(char *map_name, t_parcing *s)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(open(s->file, O_RDONLY));
	if (line == NULL)
	{
		free(line);
		ft_error("Error\nla map est vide", s);
	}
	free (line);
	if (!open(s->file, O_RDONLY))
		return (ft_error("Error\nle fichier n'est pas valide", s));
	while (map_name[i])
	{
		i++;
	}
	if (i > 4 && map_name[i - 4] == '.' && map_name[i - 3] == 'b'
		&& map_name[i - 2] == 'e'
		&& map_name[i - 1] == 'r')
		return (1);
	return (ft_error("Error\nLe fichier n'est pas en .ber", s));
}

int	ft_check_form(char *file, t_parcing *s)
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
			ft_error("Error\nla map n'est pas rectangulaire", s);
		s->line_comp = 0;
		i++;
	}
	return (1);
}

int	ft_check_walls(char *file, t_parcing *s)
{
	int		j;

	j = 0;
	if (!first_last_walls(s->mapcpy[0])
		|| !first_last_walls(s->mapcpy[map_count_line(file) - 1]))
		return (0);
	while (j < map_count_line(file))
	{
		if (s->mapcpy[j][0] != '1'
			|| s->mapcpy[j][ft_strlenn(s->mapcpy[j]) - 1] != '1')
			return (ft_error("Error\nLa map n'est pas entouree de murs", s));
		j++;
	}
	return (1);
}
