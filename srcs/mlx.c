#include "so_long.h"

int		mlx_start(t_oo_long *game)
{
	if (!(game->mlx = mlx_init()))
		return (error_msg("MLX error : funct. init doesn't work.\n"));
	printf("openning window %d x %d\n", game->len, game->max_len);
	if (!(game->win = mlx_new_window(game->mlx,
					game->max_len, game->len, "so_long")))
		return (error_msg("MLX error : funct. new_window doesn't work.\n"));
	//if (!load_texture(game))
	//	return (BAD_OUT);
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
