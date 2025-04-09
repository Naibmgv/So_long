/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:00:32 by nmagamad          #+#    #+#             */
/*   Updated: 2025/03/05 10:45:18 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memcpyy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!dest || !src)
		return (NULL);
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (n--)
		{
			*d = *s;
			d++;
			s++;
		}
	}
	return (dest);
}

// int		main(void)
// {
// char 	source[] = "salut";
// printf("%s\n", ft_memmove(source + 3, source, 5));
// printf("%s", memmove(source + 3, source, 5));
// }