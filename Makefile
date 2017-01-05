# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahunt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 15:41:53 by ahunt             #+#    #+#              #
#    Updated: 2016/11/30 15:41:58 by ahunt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc 

INC += include libft/include

LIBFT = ./libft/libft.a

LIBFT_LINK = -L libft -lft

MLX = ./minilibx_macos/libmlx.a

MLX_LINK = -L minilibx_macos -lmlx

CFLAGS += $(foreach d, $(INC), -I$d)

FRMWRK = -framework OpenGL -framework AppKit

AR = ar

RLIB = ranlib

RM = rm -rf

SRC_BASE = 	main.c \
			my_loop.c \
			draw.c \
			initialize_image.c \
			initialize_fractol.c \
			initialize_fractol_tree.c \
			julia.c \
			julia_hook.c \
			mandelbrot.c \
			mandelbrot_hook.c \
			tree.c \
			tree_hook.c \
			tree_stack.c \
			color_mapping/color_map.c \
			color_mapping/dawn.c \
			color_mapping/dusk.c \
			color_mapping/fire.c \
			color_mapping/ice.c \
			color_mapping/kryptonite.c \
			color_mapping/red_blue.c \
			color_mapping/seashore.c \
			color_mapping/rainbow_squanch.c \
			color_mapping/tree_map.c \

SRC = $(addprefix src/, $(SRC_BASE))

OBJ = $(addprefix obj/, $(SRC_BASE:.c=.o))

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(OBJ): | obj

obj:
	mkdir -p $@
	mkdir -p $@/color_mapping

obj/color_mapping/%.o: src/color_mapping/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -o $@ $^  $(CFLAGS) -L libft -lft -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

debug: $(OBJ)
	$(CC) -fsanitize=address  -o $@ $^  $(CFLAGS) -L libft -lft -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

clean:
	$(RM) $(OBJ)
	make -C ./libft clean

fdf_clean:
	$(RM) $(OBJ)

fclean: fdf_clean
	$(RM) $(NAME)
	$(RM) obj
	make -C ./libft fclean

fdf_fclean: fdf_clean
	$(RM) $(NAME)
	$(RM) obj

re: fdf_fclean all
	make -C ./libft re

.PHONY: all clean fclean re
