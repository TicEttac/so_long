#include "so_long.h"

int	error_msg(char *msg)
{
	perror(msg);
	return (0);
}

int	map_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || map[x][y] == '\0' || map[x][0] == '\0')
		return (error_msg("Open map.\n"));
	if (map[x][y] == '0')
	{
		map[x][y] = ' ';
		if (!map_fill(map, x + 1, y) || !map_fill(map, x - 1, y)
		|| !map_fill(map, x, y + 1) || !map_fill(map, x, y - 1))
			return (0);
	}
	return (1);
}

int	get_map(char *path, t_oo_long *game)
{
	int	len;
	int	fd;
	int	gnl_ret;
	char	*tmp;

	len = ft_strlen(path);
	if (ft_strcmp(path + (len - 4), ".ber"))
		return (error_msg("wrong extention"));
	if ((fd = open(path, O_RDONLY)) < 0)
		return (error_msg("Failed to open conf file.\n"));
	len = 0;
	while ((gnl_ret = get_next_line(fd, &tmp)) > 0)
	{
		gnl_ret = ft_strlen(tmp) * 50;
		if (gnl_ret > game->max_len)
			game->max_len = gnl_ret;
		free(tmp);
		len++;
	}
	free(tmp);
	if (!(game->map = malloc(sizeof(char *) * (len + 1))))
		return (error_msg("Malloc error.\n"));
	close(fd);
	if ((fd = open(path, O_RDONLY)) < 0)
		return (error_msg("Failed to open conf file.\n"));
	len = 0;
	while ((gnl_ret = get_next_line(fd, &game->map[len])))
		len++;
	game->map[len] = NULL;
	printf("len[%d]\n", len);
	return (len * 50);
}

void	free_dtab(char **dtab, int size)
{
	while (size)
	{
		free(dtab[size]);
		dtab[size] = NULL;
		size--;
	}
	free(dtab[0]);
	free(dtab);
	dtab = NULL;
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
				return (0);
			if (game->map[i][y] == 'P' && !add_start(game, i, y))
				return (0);
			if (game->map[i][y] == 'E' && !add_exit(game, i, y))
				return (0);
			if (game->map[i][y] == 'C')
				game->item_nb++;
			y++;
		}
		i++;
		y = 0;
	}
	if (game->x == -1 || game->ex_x == -1)
		return (0);
	return (1);
}

int	parser(t_oo_long *game, char *path)
{
	if (!(game->len = get_map(path, game)))
		return (error_msg("Empty conf file.\n"));
	if (!(map_check(game)) || !(map_fill(game->map, game->x, game->y)))
	{
		free_dtab(game->map, game->len);
		return (error_msg("Wrong map.\n"));
	}
	game->map[game->x][game->y] = 'P';
	printf("item_nb[%d]\n", game->item_nb);
	return (1);
}
