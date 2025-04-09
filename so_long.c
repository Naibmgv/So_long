/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:53:48 by nmagamad          #+#    #+#             */
/*   Updated: 2025/04/09 13:04:45 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *game, t_parcing *s)
{
	game->map = s->mapcpy;
	game->amount_col = s->count_collectibles;
	game->x_e = ft_pos_x(game->map, 'E');
	game->y_e = ft_pos_y(game->map, 'E');
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->y_len = 0;
	game->x_len = 0;
	while (game->map[game->y_len])
		game->y_len++;
	game->x_len = ft_strlen(game->map[0]);
	game->w = mlx_new_window(game->mlx,
			game->x_len * 64, game->y_len * 64, "So_long");
	if (!game->w)
		exit(EXIT_FAILURE);
}

void	load_images(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	game->walls = mlx_xpm_file_to_image(game->mlx, "xpm/walls.xpm", &x, &y);
	game->back = mlx_xpm_file_to_image(game->mlx, "xpm/background.xpm", &x, &y);
	game->play = mlx_xpm_file_to_image(game->mlx, "xpm/player.xpm", &x, &y);
	game->coll = mlx_xpm_file_to_image(game->mlx, "xpm/coll.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "xpm/exit.xpm", &x, &y);
	if (!game->walls || !game->back || !game->play
		|| !game->coll || !game->exit)
	{
		ft_printf("Error: .xpm image failed\n");
		mlx_destroy_window(game->mlx, game->w);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
}

void	put_images(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->y_len)
	{
		x = 0;
		while (x < g->x_len)
		{
			if (g->map[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->w, g->walls, x * 64, y * 64);
			else if (g->map[y][x] == 'P')
				mlx_put_image_to_window(g->mlx, g->w, g->play, x * 64, y * 64);
			else if (g->map[y][x] == 'E')
				mlx_put_image_to_window(g->mlx, g->w, g->exit, x * 64, y * 64);
			else if (g->map[y][x] == 'C')
				mlx_put_image_to_window(g->mlx, g->w, g->coll, x * 64, y * 64);
			else if (g->map[y][x] == '0')
				mlx_put_image_to_window(g->mlx, g->w, g->back, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int	destroy_map(t_game *game)
{
	if (game->walls)
		mlx_destroy_image(game->mlx, game->walls);
	if (game->play)
		mlx_destroy_image(game->mlx, game->play);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->coll)
		mlx_destroy_image(game->mlx, game->coll);
	if (game->w)
		mlx_destroy_window(game->mlx, game->w);
	if (game->map)
		free_map(game->map);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_parcing	t;
	t_game		game;

	if (ac != 2)
		return (1);
	init_parcing_struct(&t, av[1]);
	ft_check_map_name(av[1], &t);
	if (!ft_map_copy(av[1], &t))
		return (ft_error("Error\nL'allocation de la map à échoué", &t));
	ft_check_form(av[1], &t);
	ft_check_walls(av[1], &t);
	ft_check_p(av[1], &t);
	ft_check_e(av[1], &t);
	if (!ft_check_c(av[1], &t))
		ft_error("Error\nLa map ne contient pas de consommables", &t);
	parse(&t);
	init_game_struct(&game);
	init_window(&game, &t);
	load_images(&game);
	put_images(&game);
	mlx_hook(game.w, 17, 0, destroy_map, &game);
	mlx_key_hook(game.w, key_bind, &game);
	mlx_loop(game.mlx);
}
