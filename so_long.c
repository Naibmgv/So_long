/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magamadov <magamadov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:39:39 by nmagamad          #+#    #+#             */
/*   Updated: 2025/03/18 18:37:44 by magamadov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void printTab(char *tableau[], int lignes) {
    for (int i = 0; i < lignes; i++) {
        printf("%s", tableau[i]);  
    }
}

void	ft_freemap(char	*file, t_parcing *s)
{
	int		i;
	int		y_len;
	
	i = 0;
	y_len = map_count_line(file);
	while (i < y_len && s->mapcpy[i])
	{
		free(s->mapcpy[i]);
		i++;
	}
	free (s->mapcpy);
	free (s->line);
}

char	**final_map_copy(char *file, t_parcing *s)
{
	int		fd;
	int		i;
	
	i = 0;
	s->y_len2 = map_count_line(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	s->mapcpy = malloc(sizeof(char *) * map_count_line(file));
	if (!s->mapcpy)
		return (NULL);
	while (i < s->y_len2)
	{
		s->line = get_next_line(fd);
		if (!s->line)
			break ;
		s->mapcpy[i] = ft_strdup2(s->line);
		if (!s->mapcpy[i])
		{
			ft_freemap(file, s);
			break ;
		}
		i++;
	}
	return (s->mapcpy);
}

int	check_map_name(char *map_name)
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

int		check_form(char *file, t_parcing *s)
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

void	init_parcing(t_parcing *s)
{
	if (!s)
		return ;
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
	s->first_line_len = 0;
	s->line_comp = 0;
}

int	main(int ac, char **av)
{
	t_parcing	t;
	
	init_parcing(&t);
	if (ac != 2)
		return (1);
	if (!check_map_name(av[1]))
	{
		ft_printf("Error\nle fichier n'est pas en .ber !");
		return (1);
	}
	final_map_copy(av[1], &t);
	if (!check_form(av[1], &t))
	{
		ft_printf("Error\nLa carte n'est pas rectangulaire !");
	}
}
