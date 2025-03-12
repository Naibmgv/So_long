/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:42:13 by nmagamad          #+#    #+#             */
/*   Updated: 2025/03/12 15:31:44 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "libft/headers/libft.h"
# include "libft/headers/get_next_line.h"
# include "libft/headers/ft_printf.h"

typedef struct s_parcing
{
	char	*tmp;
	char	*line;
	char	**mapcpy;
	char	*mapcpy2;
	int		count_line;
	int		x_len;
	int 	y_len;
	int		map_len;
	int		len;
	int		i;
	int		fd;
}	t_parcing;

int		check_form(t_parcing *s);
int		check_map_name(char *map_name);
size_t	ft_strlenn(const char *str);
char	*ft_strcpy(char *dest, char *src);
char	**final_map_copy(char *file, t_parcing *s);
int		map_count_line(char *file);
int		get_map_len(int	fd);
char	*ft_strdup2(const char *s);
char	*ft_strjoin2(char const *s1, char const *s2);
void	init_parcing(t_parcing *s);
void 	testff(t_parcing *t);
char	*ft_strchr2(const char *s, int c);

#endif