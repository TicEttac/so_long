/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 03:23:57 by nisauvig          #+#    #+#             */
/*   Updated: 2022/02/08 16:04:46 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean_exit(t_oo_long *player)
{
	int	i;

	i = player->len / 50;
	mlx_destroy_image(player->mlx, player->image.img);
	mlx_clear_window(player->mlx, player->win);
	mlx_destroy_window(player->mlx, player->win);
	while (i >= 0)
	{
		free(player->map[i]);
		i--;
	}
	free(player->map);
	exit(0);
}

void	interact(t_oo_long *game, int x, int y)
{
	game->map[x][y] = '0';
	if (game->map[game->x][game->y] == 'E')
		clean_exit(game);
	if (game->map[game->x][game->y] == 'C')
		game->score++;
	game->map[game->x][game->y] = 'P';
	game->moves++;
	printf("moves[%d], score[%d]\n", game->moves, game->score);
}

void	key_press(int key, t_oo_long *game)
{
	size_t	x;
	size_t	y;

	x = (size_t)game->x;
	y = (size_t)game->y;
	if (key == W_KEY && x > 0 && game->map[x - 1][y] != '1')
		game->x -= 1;
	if (key == A_KEY && y > 0 && game->map[x][y - 1] != '1')
		game->y -= 1;
	if (key == S_KEY && x <= ft_strlen(game->map[x + 1])
		&& game->map[x + 1][y] != '1')
		game->x += 1;
	if (key == D_KEY && y <= ft_strlen(game->map[x])
		&& game->map[x][y + 1] != '1')
		game->y += 1;
	if (game->map[game->x][game->y] == 'E' && game->score != game->item_nb)
	{
		game->x = x;
		game->y = y;
		return ;
	}
	if (x != (size_t)game->x || y != (size_t)game->y)
		interact(game, x, y);
}

int	key_hook(int key, t_oo_long *player)
{
	if (key == ESC_KEY)
		clean_exit(player);
	if (key == W_KEY || key == S_KEY || key == A_KEY || key == D_KEY)
		key_press(key, player);
	return (1);
}

int	mlx_hooks(t_oo_long *player)
{
	if (!(mlx_hook(player->win, 2, (1L << 0), &key_hook, player)))
		return (ERROR);
	if (!(mlx_hook(player->win, 17, 0L, &clean_exit, player)))
		return (ERROR);
	if (!(mlx_loop_hook(player->mlx, &set_image, player)))
		return (ERROR);
	return (GOOD);
}
