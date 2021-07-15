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

# define ERROR 0
# define GOOD 1

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307

typedef struct	s_parse
{
	char	id;
	int	(*func)(int i, t_oo_long *game, int i);
}		t_parse;

typedef struct	s_img
{
	void		*img;
	int			*tab;
	int			sl;
}				t_img;

typedef	struct	s_texs
{
	int			*player;
	void		*im_player;
	int			*cons;
	void		*im_cons;
	int			*wall;
	void		*im_wall;
	int			*empty;
	void		*im_empty;
	int			*exit;
	void		*im_exit;
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
int		init_image(t_oo_long *game);
int 	load_texture_wrap(void *mlx, void *ptr, int *tab, char *path);
int		load_textures(t_oo_long *game);

#endif
