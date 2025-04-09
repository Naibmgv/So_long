/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils(3).c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:42:22 by nmagamad          #+#    #+#             */
/*   Updated: 2025/04/08 18:45:01 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_pos_y(char **mapcpy, char c)
{
	int	j;

	j = 0;
	while (mapcpy[j])
	{
		if (ft_strchrr(mapcpy[j], c))
			break ;
		j++;
	}
	return (j);
}

int	ft_pos_x(char **mapcpy, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (mapcpy[j])
	{
		if (ft_strchrr(mapcpy[j], c))
		{
			while (mapcpy[j][i] != c)
			{
				if (mapcpy[j][i] == c)
					return (i);
				i++;
			}
		}
		j++;
	}
	return (i);
}
