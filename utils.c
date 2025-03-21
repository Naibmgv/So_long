/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:05:25 by nmagamad          #+#    #+#             */
/*   Updated: 2025/03/21 11:42:57 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	s->i = 0;
	s->first_line_len = 0;
	s->line_comp = 0;
	s->line_num = 0;
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

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlenn(s1) + ft_strlenn(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		j++;
		i++;
	}
	s3[i] = '\0';
	return (s3);
}

char	*ft_strdup2(const char *s)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlenn(s);
	i = 0;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlenn(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
	{
		dst[i] = '\0';
	}
	return (ft_strlenn(src));
}

static int	ft_count_word(char const *s, char sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == sep && s[i])
			i++;
		if (s[i])
			j++;
		while (s[i] != sep && s[i])
			i++;
	}
	return (j);
}

static char	*ft_cpy(char **res, const char *s, char sep)
{
	int	len;

	while (*s)
	{
		len = 0;
		while (*s == sep && *s)
			s++;
		while (*s != sep && *s)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			*res = malloc(len + 1);
			if (*res == NULL)
				return (NULL);
			ft_strlcpy(*res, s - len, len + 1);
			res++;
		}
	}
	return (*res);
}

char	**ft_split(char const *s, char c)
{
	int		mots;
	char	**res;

	if (!s)
		return (NULL);
	mots = ft_count_word(s, c);
	res = malloc(sizeof(char *) * (mots + 1));
	if (!res)
		return (NULL);
	res[mots] = NULL;
	ft_cpy(res, s, c);
	return (res);
}

int		ft_strchr2(const char *s, int c)
{
	size_t	i;
	size_t	count;

	count = 0; 
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			count++;
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (count);
}

void printTab(char *tableau[], int lignes) {
    for (int i = 0; i < lignes; i++) {
        printf("%s|", tableau[i]);  
    }
}

char	**ft_dup_tab(char **tab)
{
	int		i;
	char	**new_tab;

	if (!tab)
		return (NULL);
	i = 0;
	while (tab[i])
		i++;
	new_tab = malloc(sizeof(char *) * (i + 1));
	if (!new_tab)
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		new_tab[i] = ft_strdup2(tab[i]);
		if (!new_tab[i])
			while (--i >= 0)
				free(new_tab[i]);
	}
	new_tab[i] = NULL;
	return (new_tab);
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
}

char	**ft_map_copy(char *file, t_parcing *s)
{
	int		fd;
	
	s->y_len2 = map_count_line(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	s->mapcpy = malloc(sizeof(char *) * map_count_line(file));
	if (!s->mapcpy)
		return (NULL);
	while (s->i < s->y_len2)
	{
		s->line = get_next_line(fd);
		if (!s->line)
			break ;
		s->mapcpy[s->i] = ft_strdup2(s->line);
		if (!s->mapcpy[s->i])
		{
			ft_freemap(file, s);
			break ;
		}
		s->i++;
	}
	free (s->line);
	// s->mapcpy[s->i] = NULL;
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

int	 ft_get_j(t_parcing *s)
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

int	 ft_get_i(t_parcing *s)
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
