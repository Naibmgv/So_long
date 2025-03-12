/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:39:39 by nmagamad          #+#    #+#             */
/*   Updated: 2025/03/12 15:48:54 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	**final_map_copy(char *file, t_parcing *s)
{
	int		fd;

	fd = open(file, O_RDONLY);
	s->mapcpy = malloc(sizeof(char *) * map_count_line(file));
	while (1)
	{
		s->line = get_next_line(fd);
		if (s->line == NULL)
			break ;
		if (s->mapcpy[s->i] == NULL)
			s->mapcpy[s->i] = ft_strdup2("");
		else
		{
			s->tmp = s->mapcpy[s->i];
			s->mapcpy[s->i] = ft_strjoin2(s->tmp, s->line);
			free (s->tmp);
			s->tmp = NULL;
		}
		s->i++;
		free (s->line);
	}
	printf("%s", s->mapcpy[0]);
	printf("%s", s->mapcpy[1]);
	printf("%s", s->mapcpy[2]);
	printf("%s", s->mapcpy[3]);
	printf("%s", s->mapcpy[4]);
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

int		strlen_map(char *str)
{
	int		i;
	
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

int	check_form(t_parcing *s)
{
	// int		i;
	int		j;
	int		first_line_len;

	// i = 0;
	j = 0;
	first_line_len = 0;
	while (j != s->i)
	{
		first_line_len = strlen_map(s->mapcpy[j++]);
		if (first_line_len != strlen_map(s->mapcpy[0]))
			return (0);
		first_line_len = 0;
	}
	
	return (1);
}

int	main(int ac, char **av)
{
	t_parcing	t;
	
	init_parcing(&t);
	if (ac != 2)
		return (1);
	if (open(av[1], O_RDONLY) < 0)
		return (ft_printf("Error\nLe descripteur de fichier est invalide"));
	final_map_copy(av[1], &t);
	if (!check_map_name(av[1]))
	{
		ft_printf("Error\nle fichier n'est pas en .ber!");
		return (1);
	}
}
// 	if (!check_form(&t))
// 	{
// 		ft_printf("Error\nle fichier n'est pas en .ber!");
// 		return (1);
// 	}
// }