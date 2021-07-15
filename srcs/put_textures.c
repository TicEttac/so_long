#include "so_long.h"

void    put_wall(int px, t_oo_long *game, int line)
{
    int x;

    x = 0;
    while (x < 2500)
    {
        game->image.tab[px + (line * game->image.sl)] = game->tex.wall[x];
        x++;
        //jump for sl each 50 into px
    }
}

void    put_empty(int px, t_oo_long *game)
{}

void    put_consumable(int px, t_oo_long *game)
{}

void    put_exit(int px, t_oo_long *game)
{}

void    put_player(int px, t_oo_long *game)
{}