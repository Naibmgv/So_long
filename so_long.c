/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:39:39 by nmagamad          #+#    #+#             */
/*   Updated: 2025/03/11 17:35:01 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*map_copy(int fd)
{
	t_struct	s;
	
	s.tmp = NULL;
	s.mapcpy = NULL;
	while (1)
	{
		s.line = get_next_line(fd);
		if (s.line == NULL)
			break ;
		if (s.mapcpy == NULL)
			s.mapcpy = ft_strdup2(s.line);
		else
		{
			s.tmp = s.mapcpy;
			s.mapcpy = ft_strjoin2(s.tmp, s.line);
			free (s.tmp);
			s.tmp = NULL;
		}
		free (s.line);
	}
	// ft_printf("%s", s.mapcpy);
	s.final_mapcpy = ft_split(s.mapcpy, '\n');
	ft_printf("%s", s.final_mapcpy[0]);
	ft_printf("%s", s.final_mapcpy[1]);
	ft_printf("%s", s.final_mapcpy[2]);
	ft_printf("%s", s.final_mapcpy[3]);
	ft_printf("%s", s.final_mapcpy[4]);
	return (s.mapcpy);
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

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	
	fd = open("map.ber", O_RDONLY);
	(void)argc;
	if (fd < 0)
		return (ft_printf("Error\nLe descripteur de fichier est invalide"));
	if (!check_map_name(argv[1]))
	{
		ft_printf("Error\nle fichier n'est pas en .ber!");
		return (0);
	}
	str = map_copy(fd);
	// printf("%s", str);
	free (str);
	// check_form(fd);
}
