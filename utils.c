/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:05:25 by nmagamad          #+#    #+#             */
/*   Updated: 2025/04/08 18:42:40 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_parcing_struct(t_parcing *s, char *filee)
{
	if (!s)
		return ;
	s->file = filee;
	s->tmp = NULL;
	s->line = NULL;
	s->mapcpy = NULL;
	s->mapcpy2 = NULL;
	s->y_len = 0;
	s->y_len1 = 0;
	s->y_len2 = 0;
	s->map_len = 0;
	s->len = 0;
	s->j = 0;
	s->i = 0;
	s->first_line_len = 0;
	s->line_comp = 0;
	s->line_num = 0;
	s->map_len2 = 0;
	s->y_len3 = 0;
	s->count_collectibles = 0;
	s->count_c = 0;
	s->count_exit = 0;
}

void	init_game_struct(t_game *g)
{
	if (!g)
		return ;
	g->map = NULL;
	g->walls = NULL;
	g->back = NULL;
	g->play = NULL;
	g->coll = NULL;
	g->exit = NULL;
	g->w = NULL;
	g->mlx = NULL;
	g->amount_col = 0;
	g->count_c = 0;
	g->x_len = 0;
	g->y_len = 0;
	g->x = 0;
	g->y = 0;
	g->x_e = 0;
	g->y_e = 0;
	g->count = 0;
}

int	first_last_walls(char *str)
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

int	map_count_line(char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		i++;
		free(line);
	}
	return (i);
}

size_t	ft_strlenn(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
