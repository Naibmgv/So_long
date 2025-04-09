/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils(2).c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:41:44 by nmagamad          #+#    #+#             */
/*   Updated: 2025/04/08 18:42:00 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map_copy(char *file, t_parcing *s)
{
	int		fd;

	s->y_len2 = map_count_line(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	s->mapcpy = malloc(sizeof(char *) * (map_count_line(file) + 1));
	if (!s->mapcpy)
		return (NULL);
	while (s->i < s->y_len2)
	{
		s->line = get_next_line(fd);
		if (!s->line)
			break ;
		s->mapcpy[s->i] = ft_strdup2(s->line);
		free(s->line);
		if (!s->mapcpy[s->i])
		{
			free_map(s->mapcpy);
			break ;
		}
		s->i++;
	}
	s->mapcpy[s->i] = NULL;
	return (s->mapcpy);
}

char	*ft_strchrr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

int	ft_get_j(t_parcing *s)
{
	s->j = 0;
	while (s->mapcpy[s->j])
	{
		if (ft_strchrr(s->mapcpy[s->j], 'P'))
			break ;
		s->j++;
	}
	return (s->j);
}

int	ft_get_i(t_parcing *s)
{
	s->i = 0;
	while (s->mapcpy[s->j][s->i])
	{
		if (s->mapcpy[s->j][s->i] == 'P')
			break ;
		s->i++;
	}
	return (s->i);
}

int	ft_tab_len(char **strs)
{
	int	len;

	len = 0;
	if (!strs)
		return (0);
	while (strs[len])
		len++;
	return (len);
}
