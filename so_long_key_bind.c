/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_bind.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:58:39 by nmagamad          #+#    #+#             */
/*   Updated: 2025/04/09 12:36:05 by nmagamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *g, int y, int x)
{
	if (g->map[y - 1][x] == '1')
		return ;
	if (g->map[y - 1][x] == 'E' && g->count_c != g->amount_col)
		return ;
	if (g->map[y - 1][x] == 'C')
		g->count_c += 1;
	g->map[y][x] = '0';
	g->map[y - 1][x] = 'P';
	g->count += 1;
	ft_printf("%d", g->count);
}

void	move_left(t_game *g, int y, int x)
{
	if (g->map[y][x - 1] == '1')
		return ;
	if (g->map[y][x - 1] == 'E' && g->amount_col != g->count_c)
		return ;
	if (g->map[y][x - 1] == 'C')
		g->count_c += 1;
	g->map[y][x] = '0';
	g->map[y][x - 1] = 'P';
	g->count++;
	ft_printf("%d", g->count);
}

void	move_down(t_game *g, int y, int x)
{
	if (g->map[y + 1][x] == '1')
		return ;
	if (g->map[y + 1][x] == 'E' && g->amount_col != g->count_c)
		return ;
	if (g->map[y + 1][x] == 'C')
		g->count_c += 1;
	g->map[y][x] = '0';
	g->map[y + 1][x] = 'P';
	g->count++;
	ft_printf("%d", g->count);
}

void	move_right(t_game *g, int y, int x)
{
	if (g->map[y][x + 1] == '1')
		return ;
	if (g->map[y][x + 1] == 'E' && g->amount_col != g->count_c)
		return ;
	if (g->map[y][x + 1] == 'C')
		g->count_c += 1;
	g->map[y][x] = '0';
	g->map[y][x + 1] = 'P';
	g->count++;
	ft_printf("%d", g->count);
}

int	key_bind(int keycode, void *param)
{
	int		x;
	int		y;
	t_game	*g;

	g = (t_game *)param;
	x = ft_pos_x(g->map, 'P');
	y = ft_pos_y(g->map, 'P');
	if (keycode == KEY_ESC)
		destroy_map(g);
	if (keycode == KEY_W)
		move_up(g, y, x);
	if (keycode == KEY_D)
		move_right(g, y, x);
	if (keycode == KEY_A)
		move_left(g, y, x);
	if (keycode == KEY_S)
		move_down(g, y, x);
	if (g->map[g->y_e][g->x_e] == 'P' && g->count_c == g->amount_col)
		destroy_map(g);
	put_images(g);
	return (1);
}
