#include "so_long.h"

int load_texture_wrap(void *mlx, t_tex *tex, char *path)
{
    int x;
    int y;
    int en;

	if (!(tex->im = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height)))
		return (error_msg("Texture open error.\n"));
	if (!(tex->tab = (int *)mlx_get_data_addr(
				tex->im, &x, &y, &en)))
		return (error_msg("Texture tabbing error.\n"));
    return (1);
}

int		load_textures(t_oo_long *game)
{
	if (!(load_texture_wrap(game->mlx, &game->tex.player, "./textures/player.xpm")))
		return (ERROR);
	if (!(load_texture_wrap(game->mlx, &game->tex.cons, "./textures/cons.xpm")))
		return (ERROR);
	if (!(load_texture_wrap(game->mlx, &game->tex.wall, "./textures/wall.xpm")))
		return (ERROR);
	if (!(load_texture_wrap(game->mlx, &game->tex.empty, "./textures/empty.xpm")))
		return (ERROR);
	if (!(load_texture_wrap(game->mlx, &game->tex.exit, "./textures/exit.xpm")))
		return (ERROR);
	if (!(load_texture_wrap(game->mlx, &game->tex.enemy, "./textures/enemy.xpm")))
		return (ERROR);
	return (GOOD);
}
