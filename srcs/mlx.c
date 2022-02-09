/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 03:56:14 by nisauvig          #+#    #+#             */
/*   Updated: 2022/02/09 14:04:53 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_start(t_oo_long *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (error_msg("MLX error : funct. init doesn't work.\n"));
	printf("openning window %d x %d\n", game->len, game->max_len);
	game->win = mlx_new_window(game->mlx,
			game->max_len, game->len, "so_long");
	if (!game->win)
		return (error_msg("MLX error : funct. new_window doesn't work.\n"));
	if (!load_textures(game))
		return (0);
	return (1);
}

int	init_image(t_oo_long *game)
{
	int		bpp;
	int		endian;

	bpp = 32;
	endian = 0;
	game->image.img = mlx_new_image(game->mlx, game->max_len, game->len);
	if (!game->image.img)
		return (ERROR);
	game->image.tab = (int *)mlx_get_data_addr(game->image.img, &bpp,
			&game->image.sl, &endian);
	if (!game->image.tab)
		return (ERROR);
	if (!(set_image(game)))
		return (ERROR);
	return (GOOD);
}

void	put_mapline_window(t_oo_long *game, char *mapline, int i)
{
	static const t_parse	c[] = {{' ', &put_empty}, {'1', &put_wall},
	{'C', &put_consumable}, {'E', &put_exit}, {'P', &put_player},
	{'0', &put_empty}};
	int						len;
	int						list;

	len = 0;
	while (mapline && mapline[len])
	{
		list = 0;
		while (c[list].id != mapline[len])
			list++;
		c[list].func(len, game, i);
		len++;
	}
}

int	set_image(t_oo_long *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		put_mapline_window(game, game->map[i], i);
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->image.img, 0, 0);
	return (GOOD);
}
