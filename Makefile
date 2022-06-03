
NAME = so_long

SRCS =		main.c			\
			parser.c		\
			parser_utils.c	\
			parser_utils2.c	\
			mlx.c			\
			textures.c		\
			hooks.c			\
			put_textures.c	\

GNL_SRCS =	get_next_line.c		\
		get_next_line_utils.c	\

OBJS = $(addprefix srcs/, $(SRCS))
GNL_OBJS = $(addprefix gnl/, $(GNL_SRCS))

LIB =	lib/libft.a	\
		lib/libmlx.a\

CFLAGS = -Wall -Werror -Wextra -I includes -lbsd -lmlx -lXext -lX11 -lm -o

CC = gcc

all:	$(NAME)

$(NAME): $(OBJS)
	@make -C ./libft all
	@make -C minilibX
	@mkdir -p lib
	@mv libft/libft.a lib/
	@mv minilibX/libmlx.a lib/
	@cp minilibX/mlx.h ./includes
	@${CC} ${CFLAGS} ${NAME} ${GNL_OBJS} ${OBJS} ${LIB} #&& printf "%-60b\r" "$(_GREEN)$(ECHO)$(_CYAN) Compilation $@"
	@echo "compiling $@"

clean:
	@rm -rf lib/
	@rm -rf includes/mlx.h
	@make -C minilibX clean
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

git: fclean
	@git add .
	@git commit -m "$@"
	@git push

.SILENT: all clean fclean re
.PHONY: all clean fclean re
