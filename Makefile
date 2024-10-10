CC=cc
NAME = cub3D
SRCPATH = src/
LIBFT = libft/libft.a
LIBMLX	= MLX42
SRCS = main.c \
		setup/init.c \
		setup/parsing.c \
		exec/map.c \
		exec/hook.c \
		exec/utils.c \
		exec/raycasting.c \
		exec/free.c
SRCSINC = $(addprefix $(SRCPATH), $(SRCS))
HEADERS = -I includes -I $(LIBMLX)/include
OBJS = $(SRCSINC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = $(LIBMLX)/build/libmlx42.a $(LIBFT) -ldl -lglfw -pthread -lm 

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) $(LIBFT)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make --no-print-directory -C $(LIBMLX)/build -j4
	$(CC) $(OBJS) $(LFLAGS) $(HEADERS) -o $(NAME)

$(LIBFT):
	@make -j8 -C libft/ all

fclean: clean
	rm -f $(NAME)
	rm -rf $(LIBMLX)/build
	@make -C libft/ clean

clean:
	rm -f $(OBJS)
	@make -C libft/ clean

re: fclean all

.PHONY: all fclean clean re
