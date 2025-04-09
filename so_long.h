/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:42:13 by nmagamad          #+#    #+#             */
/*   Updated: 2025/04/09 14:51:44 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/headers/libft.h"
# include "libft/headers/get_next_line.h"
# include "libft/headers/ft_printf.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_game
{
	char	**map;
	void	*walls;
	void	*back;
	void	*play;
	void	*coll;
	void	*exit;
	void	*w;
	void	*mlx;
	int		amount_col;
	int		count_c;
	int		x_len;
	int		y_len;
	int		x;
	int		y;
	int		x_e;
	int		y_e;
	int		count;
}	t_game;

typedef struct s_parcing
{
	char	*file;
	char	*tmp;
	char	*line;
	char	**mapcpy;
	char	**mapcpy2;
	int		count_collectibles;
	int		count_line;
	int		count_c;
	int		count_exit;
	int		y_len;
	int		y_len1;
	int		y_len2;
	int		y_len3;
	int		map_len2;
	int		map_len;
	int		len;
	int		j;
	int		i;
	int		first_line_len;
	int		line_comp;
	int		line_num;
}	t_parcing;

void	init_game_struct(t_game *g);
void	init_parcing_struct(t_parcing *s, char *filee);
void	ft_check_chars(t_parcing *s);
int		ft_check_map_name(char *map_name, t_parcing *s);
int		ft_check_form(char *file, t_parcing *s);
int		ft_check_walls(char *file, t_parcing *s);
int		ft_check_c(char *file, t_parcing *s);
int		ft_check_p(char *file, t_parcing *s);
int		ft_check_e(char *file, t_parcing *s);
int		parse(t_parcing *s);
int		ft_error(char *print, t_parcing *s);
char	**ft_map_copy(char *file, t_parcing *s);
int		map_count_line(char *file);
char	*ft_strdup2(const char *s);
char	*ft_strjoin2(char const *s1, char const *s2);
size_t	ft_strlenn(const char *str);
int		ft_strchr2(const char *s, char c);
int		strlen_map(char *str);
void	ft_freemap(char *file, t_parcing *s);
char	**ft_map_copy(char *file, t_parcing *s);
int		first_last_walls(char *str);
char	**ft_dup_tab(char **tab);
char	*ft_strchrr(const char *s, int c);
int		ft_get_i(t_parcing *s);
int		ft_get_j(t_parcing *s);
int		ft_tab_len(char **strs);
void	put_images(t_game *game);
void	load_images(t_game *game);
void	init_window(t_game *game, t_parcing *s);
int		key_bind(int keycode, void *param);
int		destroy_map(t_game *game);
void	handle_mouvement(t_game *g, int y, int x, int new);
int		ft_pos_y(char **mapcpy, char c);
int		ft_pos_x(char **mapcpy, char c);
void	free_map(char **array);
int		ft_pos_x(char **mapcpy, char c);
int		ft_pos_y(char **mapcpy, char c);
void	printtab(char *tableau[], int lignes);

#endif