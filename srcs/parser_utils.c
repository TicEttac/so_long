#include "so_long.h"

int add_start(t_oo_long *game, int x, int y)
{
    if (game->x == -1 && game->y == -1)
    {
        game->x = x;
        game->y = y;
        game->map[x][y] = '0';
        return (1);
    }
    game->map[x][y] = '0';
    return (1);
}

int add_exit(t_oo_long *game, int x, int y)
{
    if (game->ex_x == -1 && game->ex_y == -1)
    {
        game->ex_x = x;
        game->ex_y = y;
        return (1);
    }
    game->map[x][y] = '0';
    return (1);
}
