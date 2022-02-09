/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 03:43:21 by nisauvig          #+#    #+#             */
/*   Updated: 2022/02/08 16:23:01 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || map[x][y] == '\0' || map[x][0] == '\0')
		return (ERROR);
	if (map[x][y] == '0')
	{
		map[x][y] = ' ';
		if (!map_fill(map, x + 1, y) || !map_fill(map, x - 1, y)
			|| !map_fill(map, x, y + 1) || !map_fill(map, x, y - 1))
			return (0);
	}
	return (1);
}

int	get_map_len(t_oo_long *game, int fd)
{
	int		len;
	int		gnl_ret;
	char	*tmp;

	len = 0;
	gnl_ret = get_next_line(fd, &tmp);
	while (gnl_ret > 0)
	{
		gnl_ret = ft_strlen(tmp) * 50;
		if (gnl_ret > game->max_len)
			game->max_len = gnl_ret;
		free(tmp);
		len++;
		gnl_ret = get_next_line(fd, &tmp);
	}
	free(tmp);
	return (len);
}

int	get_map(char *path, t_oo_long *game)
{
	int		len;
	int		fd;

	len = ft_strlen(path);
	if (ft_strcmp(path + (len - 4), ".ber"))
		return (error_msg("wrong extention"));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_msg("Failed to open conf file.\n"));
	len = get_map_len(game, fd);
	game->map = malloc(sizeof(char *) * (len + 1));
	if (!game->map)
		return (error_msg("Malloc error.\n"));
	close(fd);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_msg("Failed to open conf file.\n"));
	len = 0;
	while (get_next_line(fd, &game->map[len]))
		len++;
	free(game->map[len]);
	game->map[len] = NULL;
	return (len * 50);
}

int	map_check(t_oo_long *game)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < (game->len / 50))
	{
		while (game->map[i][y])
		{
			if (!(ft_strchr("10CEP", game->map[i][y])))
				return (ERROR);
			if (game->map[i][y] == 'P' && !add_start(game, i, y))
				return (ERROR);
			if (game->map[i][y] == 'E' && !add_exit(game, i, y))
				return (ERROR);
			if (game->map[i][y] == 'C')
				game->item_nb++;
			y++;
		}
		i++;
		y = 0;
	}
	if (game->x == -1 || game->ex_x == -1 || game->item_nb == 0)
		return (ERROR);
	return (GOOD);
}

int	parser(t_oo_long *game, char *path)
{
	game->map = NULL;
	game->len = get_map(path, game);
	if (!game->len)
		return (ERROR);
	if (!(map_check(game)) || !(map_fill(game->map, game->x, game->y)))
		return (ERROR);
	game->map[game->x][game->y] = 'P';
	return (GOOD);
}
