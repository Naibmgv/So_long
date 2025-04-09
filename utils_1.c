/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils(1).c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:40:41 by nmagamad          #+#    #+#             */
/*   Updated: 2025/04/08 18:41:18 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_strchr2(const char *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	if (s[i] == c)
		return (1);
	return (count);
}

void	printtab(char *tableau[], int lignes)
{
	int	i;

	i = 0;
	while (i < lignes)
	{
		ft_printf("%s\n", tableau[i]);
		i++;
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
