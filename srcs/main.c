#include "so_long.h"

void	set_struct(t_oo_long *game)
{
	game->len = 0;
	game->max_len = 0;
	game->x = -1;
	game->y = -1;
	game->ex_x = -1;
	game->ex_y = -1;
	game->map = NULL;
}

int	usage(char *s)
{
	printf("%s\n", s);
	printf("usage\n");
	return (0);
}

int main(int ac, char **av)
{
	t_oo_long	game;

	if (ac != 2)
		return (usage(NULL));
	set_struct(&game);
	if (!(parser(&game, av[1])))
		return (usage("MAP UNPARSED\n"));
	mlx_start(&game);
	init_image(&game);
	mlx_loop(game.mlx);
	free_dtab(game.map, game.len);
	return (0);
}
