# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amontano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/16 21:04:13 by amontano          #+#    #+#              #
#    Updated: 2018/06/27 02:26:29 by amontano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99
SOURCE = ft_strjoin.c ft_putnbr_fd.c ft_putendl_fd.c ft_putendl.c \
		 ft_putstr_fd.c ft_putchar_fd.c ft_putnbr.c ft_strsplit.c \
		 ft_strtrim.c ft_strsub.c ft_strnequ.c ft_strequ.c ft_strmapi.c \
		 ft_strmap.c ft_striteri.c ft_striter.c ft_strdel.c ft_strclr.c \
		 ft_memalloc.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		 ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
		 ft_putstr.c ft_strlen.c ft_isupper.c ft_islower.c ft_isalpha.c \
		 ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c \
		 ft_toupper.c ft_atoi.c ft_itoa.c ft_iswhitespace.c ft_strdup.c \
		 ft_strndup.c ft_strcpy.c ft_strncpy.c ft_strcmp.c ft_strncmp.c \
		 ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcat.c \
		 ft_strncat.c ft_strlcat.c ft_strnew.c ft_bzero.c ft_lstadd.c \
		 ft_lstmap.c ft_lstiter.c ft_lstdelone.c ft_lstdel.c ft_lstnew.c \
		 ft_wordcount.c ft_strcapitalize.c get_next_line.c ft_strjoin.c \
		 ft_lstrev.c ft_lstcount.c ft_abs.c ft_wordcount_d.c \
		 ft_listaddend.c \

SRC_PATH = src/
SRC_POS = $(addprefix $(SRC_PATH), $(SOURCE))
OBJ = $(SRC_POS:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o : $.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
