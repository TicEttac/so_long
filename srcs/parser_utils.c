/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 03:42:39 by nisauvig          #+#    #+#             */
/*   Updated: 2021/08/11 03:42:41 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	add_start(t_oo_long *game, int x, int y)
{
	if (game->x == -1 && game->y == -1)
	{
		game->x = x;
		game->y = y;
		game->map[x][y] = '0';
		return (1);
	}
	game->map[x][y] = '0';
	return (1);
}

int	add_exit(t_oo_long *game, int x, int y)
{
	if (game->ex_x == -1 && game->ex_y == -1)
	{
		game->ex_x = x;
		game->ex_y = y;
		return (1);
	}
	game->map[x][y] = '0';
	return (1);
}
