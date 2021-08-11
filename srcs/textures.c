/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 03:34:46 by nisauvig          #+#    #+#             */
/*   Updated: 2021/08/11 03:34:48 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_texture_wrap(void *mlx, t_tex *tex, char *path)
{
	int	x;
	int	y;
	int	en;

	tex->im = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height);
	if (!tex->im)
		return (error_msg("Texture open error.\n"));
	tex->tab = (int *)mlx_get_data_addr(tex->im, &x, &y, &en);
	if (!tex->tab)
		return (error_msg("Texture tabbing error.\n"));
	return (1);
}

int	load_textures(t_oo_long *game)
{
	if (!(load_texture_wrap(game->mlx, &game->tex.player,
				"./textures/player.xpm")))
		return (ERROR);
	if (!(load_texture_wrap(game->mlx, &game->tex.cons, "./textures/cons.xpm")))
		return (ERROR);
	if (!(load_texture_wrap(game->mlx, &game->tex.wall, "./textures/wall.xpm")))
		return (ERROR);
	if (!(load_texture_wrap(game->mlx, &game->tex.empty,
				"./textures/empty.xpm")))
		return (ERROR);
	if (!(load_texture_wrap(game->mlx, &game->tex.exit, "./textures/exit.xpm")))
		return (ERROR);
	return (GOOD);
}
