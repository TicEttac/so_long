#include "so_long.h"

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
	if (key == S_KEY && x <= ft_strlen(game->map[x + 1]) && game->map[x + 1][y] != '1')
		game->x += 1;
	if (key == D_KEY && y <= ft_strlen(game->map[x]) && game->map[x][y + 1] != '1')
		game->y += 1;
}

int	clean_exit(t_oo_long *player)
{
	int	i;

	i = player->len;
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
	return (0);
}

int	key_hook(int key, t_oo_long *player)
{
	if (key == ESC_KEY)
		return (clean_exit(player));
	if (key == W_KEY || key == S_KEY || key == A_KEY || key == D_KEY)
		key_press(key, player);
	return (set_image(player));
}

int	mlx_hooks(t_oo_long *player)
{

    if (!(mlx_hook(player->win, 2, (1L<<0), &key_hook, player)))
        return (ERROR);
	//mlx_loop_hook(player->mlx, &game_loop, player);
	return (GOOD);
}