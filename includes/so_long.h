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

typedef	struct			s_enemy
{
	int					way;
	int					x;
	int					y;
	struct s_enemy		*next;
}						t_enemy;

typedef struct			s_img
{
	void				*img;
	int					*tab;
	int					sl;
}						t_img;

typedef	struct	s_tex
{
	int			*tab;
	void		*im;
	int			width;
	int			height;
}				t_tex;


typedef	struct	s_texs
{
	t_tex		wall;
	t_tex		empty;
	t_tex		cons;
	t_tex		player;
	t_tex		exit;
	t_tex		enemy;
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
	int			score;
	int			moves;
	int			item_nb;
	t_enemy		*enemies;
	t_img		image;
	t_texs		tex;

}		t_oo_long;

typedef struct	s_parse
{
	char	id;
	void	(*func)(int i, t_oo_long *game, int line);
}		t_parse;

int		usage();
void	free_dtab(char **dtab, int size);
int		error_msg(char *msg);
int		set_image(t_oo_long *game);

int		parser(t_oo_long *game, char *path);
int 	add_start(t_oo_long *game, int x, int y);
int 	add_exit(t_oo_long *game, int x, int y);
int		add_enemy(t_oo_long *game, int x, int y);


int		mlx_start(t_oo_long *game);
int		init_image(t_oo_long *game);
int 	load_texture_wrap(void *mlx, t_tex *tex, char *path);
int		load_textures(t_oo_long *game);
int		mlx_hooks(t_oo_long *player);

void    put_wall(int len, t_oo_long *game, int line);
void    put_empty(int len, t_oo_long *game, int line);
void    put_consumable(int len, t_oo_long *game, int line);
void    put_exit(int len, t_oo_long *game, int line);
void    put_player(int len, t_oo_long *game, int line);
void    vert_enemy(int len, t_oo_long *game, int i);
void	hor_enemy(int len, t_oo_long *game, int i);

#endif
