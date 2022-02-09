/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 04:02:12 by nisauvig          #+#    #+#             */
/*   Updated: 2022/02/08 16:25:01 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_struct(t_oo_long *game)
{
	game->len = 0;
	game->max_len = 0;
	game->x = -1;
	game->y = -1;
	game->ex_x = -1;
	game->ex_y = -1;
	game->score = 0;
	game->moves = 0;
	game->item_nb = 0;
	game->map = NULL;
}

int	usage(char *s)
{
	printf("%s\n", s);
	printf("usage : ./so_long {MAP_PATH}.ber\n\n");
	printf("map is defined by :\n");
	printf("- 1 for the wall\n- 0 for empty space\n- P for the player\n");
	printf("- C for the collectible\n- E for the exit.\n");
	printf("Map must be closed by walls.\n");
	printf("You need to collect every collectible");
	printf(" before going to the exit.\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_oo_long	game;

	if (ac != 2)
		return (usage("Wrong arguments."));
	set_struct(&game);
	if (!(parser(&game, av[1])))
		return (usage("Map unparsed."));
	if (!mlx_start(&game))
	{
		free_dtab(game.map, game.len / 50);
		return (1);
	}
	init_image(&game);
	mlx_hooks(&game);
	mlx_loop(game.mlx);
	free_dtab(game.map, game.len / 50);
	return (0);
}
