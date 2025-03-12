/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:42:13 by nmagamad          #+#    #+#             */
/*   Updated: 2025/03/11 17:33:43 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "libft/headers/libft.h"
# include "libft/headers/get_next_line.h"
# include "libft/headers/ft_printf.h"

typedef struct s_struct
{
	char	**final_mapcpy;
	char	*tmp;
	char	*line;
	char	*mapcpy;
	int		x_len;
	int 	y_len;
	int		map_len;
	int		len;
}	t_struct;

int		check_form(int	fd);
int		check_map_name(char *map_name);
size_t	ft_strlenn(const char *str);
char	*ft_strcpy(char *dest, char *src);
char	*map_copy(int fd);
int		get_map_len(int	fd);
char	*ft_strdup2(const char *s);
char	*ft_strjoin2(char const *s1, char const *s2);
// char	**ft_split(char const *s, char c);

#endif