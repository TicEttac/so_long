#include "so_long.h"

void    add_enemy(t_oo_long *game, int x, int y)
{
    t_enemy *ptr;

    ptr = game->enemies;
    while (ptr && ptr->next != NULL)
        ptr = ptr->next;
    if (!(ptr = malloc(sizeof(t_enemy))))
        return (error_msg("Malloc error\n"));
    ptr.way = 1;
    ptr.x = x;
    ptr.y = y;
    ptr->next = NULL;
    return (GOOD);
}

void    hor_enemy(int len, t_oo_long *game, int i)
{
    t_enemy *ptr;

    ptr = game->enemies;
    while ((game->x != ptr.x || game->y != ptr.y) && ptr->next != NULL)
        ptr = ptr->next;
    if (!(ft_strchr("1CE", game->map[ptr.x + ptr.way][ptr.y])))
        ptr.x += ptr.way;
    else
        ptr.way *= -1;
    return (GOOD);
}

int     vert_enemy(int len, t_oo_long *game, int i)
{    t_enemy *ptr;

    ptr = game->enemies;
    while ((game->x != ptr.x || game->y != ptr.y) && ptr->next != NULL)
        ptr = ptr->next;
    if (!(ft_strchr("1CE", game->map[ptr.x][ptr.y + ptr.way])))
        ptr.y += ptr.way;
    else
        ptr.way *= -1;
    return (GOOD);
}