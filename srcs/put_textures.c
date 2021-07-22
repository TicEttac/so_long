#include "so_long.h"

void    put_wall(int len, t_oo_long *game, int line)
{
    int x;
    int px;

    x = 0;
    px = len * 50 + line * 50 * game->max_len;
    while (x < game->tex.wall.width * game->tex.wall.height)
    {
        game->image.tab[px] = game->tex.wall.tab[x];
        x++;
        px++;
        if (!(px % 50))
            px += game->max_len - 50;
    }
}

void    put_empty(int len, t_oo_long *game, int line)
{
    int x;
    int px;

    x = 0;
    px = len * 50 + line * 50 * game->max_len;
    while (x < game->tex.empty.width * game->tex.empty.height)
    {
        game->image.tab[px] = game->tex.empty.tab[x];
        x++;
        px++;
        if (!(px % 50))
            px += game->max_len - 50;
    }
}

void    put_consumable(int len, t_oo_long *game, int line)
{
    int x;
    int px;

    x = 0;
    px = len * 50 + line * 50 * game->max_len;
    put_empty(len, game, line);
    while (x < game->tex.cons.width * game->tex.cons.height)
    {
        if (game->tex.cons.tab[x] != -16777216)
            game->image.tab[px] = game->tex.cons.tab[x];
        x++;
        px++;
        if (!(px % 50))
            px += game->max_len - 50;
    }
}

void    put_exit(int len, t_oo_long *game, int line)
{
    int x;
    int px;

    x = 0;
    px = len * 50 + line * 50 * game->max_len;
    put_empty(len, game, line);
    while (x < game->tex.exit.width * game->tex.exit.height)
    {
        if (game->tex.exit.tab[x] != -16777216)
            game->image.tab[px] = game->tex.exit.tab[x];
        x++;
        px++;
        if (!(px % 50))
            px += game->max_len - 50;
    }
}

void    put_player(int len, t_oo_long *game, int line)
{
    int x;
    int px;

    x = 0;
    px = len * 50 + line * 50 * game->max_len;
    put_empty(len, game, line);
    while (x < game->tex.player.width * game->tex.player.height)
    {
        if (game->tex.player.tab[x] != -16777216)
            game->image.tab[px] = game->tex.player.tab[x];
        x++;
        px++;
        if (!(px % 50))
            px += game->max_len - 50;
    }
}