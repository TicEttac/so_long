#include "so_long.h"

int		load_texture(t_oo_long *game)
{
	int		x;
	int		y;
	int		sl;
	int		bpp;
	int		en;

	game->tex.im_player = mlx_xpm_file_to_image(game->mlx, "../textures/player.xpm", &x, &y);
	game->tex.player = (int *)mlx_get_data_addr(game->tex.im_player, &bpp, &sl, &en);
	game->tex.im_wall = mlx_xpm_file_to_image(game->mlx, "../textures/wall.xpm", &x, &y);
	game->tex.wall = (int *)mlx_get_data_addr(game->tex.im_wall, &bpp, &sl, &en);
	game->tex.im_cons = mlx_xpm_file_to_image(game->mlx, "../textures/cons.xpm", &x, &y);
	game->tex.cons = (int *)mlx_get_data_addr(game->tex.im_cons, &bpp, &sl, &en);
	game->tex.im_empty = mlx_xpm_file_to_image(game->mlx, "../textures/empty.xpm", &x, &y);
	game->tex.empty = (int *)mlx_get_data_addr(game->tex.im_empty, &bpp, &sl, &en);
	return (1);
}

int		mlx_start(t_oo_long *game)
{
	if (!(game->mlx = mlx_init()))
		return (error_msg("MLX error : funct. init doesn't work.\n"));
	printf("openning window %d x %d\n", game->len, game->max_len);
	if (!(game->win = mlx_new_window(game->mlx,
					game->max_len, game->len, "so_long")))
		return (error_msg("MLX error : funct. new_window doesn't work.\n"));
	if (!load_texture(game))
		return (0);
	return (1);
}

void	init_image(t_oo_long *game)
{
	int		bpp;
	int		endian;

	bpp = 32;
	endian = 0;
	game->image.img = mlx_new_image(game->mlx, game->max_len, game->len);
	//player->image.sl = player->file->win[0];
	game->image.tab = (int*)mlx_get_data_addr(game->image.img, &bpp,
	&game->image.sl, &endian);
	//rendering(game);
}
