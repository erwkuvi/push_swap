# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 14:00:19 by ekuchel           #+#    #+#              #
#    Updated: 2023/06/09 11:54:02 by ekuchel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_check.c ft_printf.c ft_format.c ft_printfc.c ft_printfs.c \
ft_printfd.c ft_printfu.c ft_printfx.c ft_printfp.c

SRC_OBJ = $(SRC:.c=.o)

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(LIB) $(NAME) $(SRC_OBJ)

clean:
	$(RM) $(SRC_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
