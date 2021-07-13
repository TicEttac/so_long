#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct	s_img
{
	void		*img;
	int			*tab;
	int			sl;
}				t_img;

typedef	struct	s_texs
{
	int			*player;
	int			*cons;
	int			*wall;
	int			*empty;
	int			*exit;
}				t_texs;


typedef	struct	s_o_long
{
	char		**map;
	int			len;
	int			max_len;
	int			x;
	int			y;
	int			ex_x;
	int			ex_y;
	void		*mlx;
	void		*win;
	t_img		image;
	t_texs		tex;

}		t_oo_long;

int		usage();
int		parser(t_oo_long *game, char *path);
int 	add_start(t_oo_long *game, int x, int y);
int 	add_exit(t_oo_long *game, int x, int y);
void	free_dtab(char **dtab, int size);
int		error_msg(char *msg);
int		mlx_start(t_oo_long *game);

#endif
