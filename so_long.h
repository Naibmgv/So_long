/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:42:13 by nmagamad          #+#    #+#             */
/*   Updated: 2025/03/21 11:06:08 by nmagamad         ###   ########.fr       */
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
	char	**mapcpy2;
	int		count_line;
	int 	y_len;
	int 	y_len1;
	int 	y_len2;
	int		map_len;
	int		len;
	int		j;
	int		i;
	int		first_line_len;
	int		line_comp;
	int		line_num;
}	t_parcing;

void	init_parcing(t_parcing *s);
int		ft_check_form(char *file, t_parcing *s);
int		ft_check_map_name(char *map_name);
size_t	ft_strlenn(const char *str);
char	*ft_strcpy(char *dest, char *src);
char	**ft_map_copy(char *file, t_parcing *s);
int		map_count_line(char *file);
char	*ft_strdup2(const char *s);
char	*ft_strjoin2(char const *s1, char const *s2);
void	init_parcing(t_parcing *s);
int		ft_strchr2(const char *s, int c);
int		strlen_map(char *str); 
void	ft_freemap(char	*file, t_parcing *s);
char	**ft_map_copy(char *file, t_parcing *s);
void	printTab(char *tableau[], int lignes);
int		first_last_walls(char *str);
char	**ft_dup_tab(char **tab);
char	*ft_strchrr(const char *s, int c);
int		ft_get_i(t_parcing *s);
int		ft_get_j(t_parcing *s);

#endif