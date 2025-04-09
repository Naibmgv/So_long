/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:34:43 by nmagamad          #+#    #+#             */
/*   Updated: 2025/03/05 10:45:18 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

size_t	ft_strlenn(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
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
