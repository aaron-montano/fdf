# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amontano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/25 03:44:24 by amontano          #+#    #+#              #
#    Updated: 2018/07/10 01:47:25 by amontano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

SRC = main.c		\
	  read.c		\
	  draw.c		\
	  util.c		\
	  img.c			\
	  interpolate.c	\
	  transform.c	\
	  mouse.c		\
	  keyboard.c	\

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_DIR = obj/

MLX_PATH = minilibx_macos/
MLX = $(addprefix $(MLX_PATH), mlx.a)
MLX_DIR = -I ./minilibx_macos/
MLX_LNK = -L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

FT = libft/
LIBFT = $(addprefix $(FT), libft.a)
FT_DIR = -I ./libft/src/
FT_LNK = -L ./libft/ -lft

SRC_DIR = ./src/
INC_DIR = ./includes/
OBJ_DIR = ./obj/

all: obj $(LIBFT) $(MLX_DIR) $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_DIR) -I $(INC_DIR) -o $@ -c $<

$(LIBFT):
	make -C $(FT)

$(MLX_DIR):
	make -C $(MLX_PATH)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK)  -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(FT) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all

.PHONY: all clean fclean re

