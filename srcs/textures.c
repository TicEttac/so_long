#include "so_long.h"

int load_texture_wrap(void *mlx, void *ptr, int *tab, char *path)
{
    int x;
    int y;
    int en;

	if (!(ptr = mlx_xpm_file_to_image(mlx, path, &x, &y)))
		return (error_msg("Texture open error.\n"));
	if (!(tab = (int *)mlx_get_data_addr(
				ptr, &x, &y, &en)))
		return (error_msg("Texture tabbing error.\n"));
    return (1);
}

int		load_textures(t_oo_long *game)
{
	if (!(load_texture_wrap(game->mlx, game->tex.im_player, game->tex.player, "./textures/player.xpm")))
		return (ERROR);
	if (!(load_texture_wrap(game->mlx, game->tex.im_cons, game->tex.cons, "./textures/cons.xpm")))
		return (ERROR);
	if (!(load_texture_wrap(game->mlx, game->tex.im_wall, game->tex.wall, "./textures/wall.xpm")))
		return (ERROR);
	if (!(load_texture_wrap(game->mlx, game->tex.im_empty, game->tex.empty, "./textures/empty.xpm")))
		return (ERROR);
	//if (!(load_texture_wrap(game->mlx, game->tex.im_exit, game->tex.exit, "../textures/exit.xpm")))
		//return (ERROR);
	printf("texture all done\n");
	return (GOOD);
}
