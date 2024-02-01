# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 20:42:34 by ekuchel           #+#    #+#              #
#    Updated: 2023/07/06 17:34:04 by ekuchel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	./src/push_swap.c \
		./src/utils.c \
		./src/utils2.c \
		./src/utils3.c \
		./src/utils4.c \
		./src/utils5.c \
		./src/checkers.c \
		./src/checkers2.c \
		./src/operations.c \
		./src/operations2.c \
		./src/stack_c.c \
		./src/execution.c \
# tester.c

LIBFT = ./lib/libft/libft.a
LIBFTPRINTF = ./lib/libftprintf/libftprintf.a

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address
RM = rm -rf
CC = gcc #-g

all: $(NAME)

$(NAME): $(LIBFT) $(LIBFTPRINTF) $(SRC)
	$(CC) $(CFLAGS) -I./lib $(LIBFT) $(LIBFTPRINTF) $(SRC) -o $(NAME)

$(LIBFT):
	make -s -C ./lib/libft/

$(LIBFTPRINTF):
	make -s -C ./lib/libftprintf/

# %.o: %.cc
# 	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./lib/libft/
	make clean -C ./lib/libftprintf/

# $(RM) -f $(SRC_OBJ) $(SRC_OBJB)

fclean:
	make fclean -C ./lib/libft/
	make fclean -C ./lib/libftprintf/
	$(RM) -f $(NAME)

sclean:
	$(RM) -f $(NAME)

re: sclean all

test: $(NAME)
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = -839 -1320 -1670 954 -115)
	./push_swap $(NUMBERS) | ./checker_Mac $(NUMBERS)
	@echo "********************"

testr3: $(NAME)
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 3 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo "./push_swap $(NUMBERS) | wc -l"
	@echo "********************"

testr4: $(NAME)
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 4 | tr '\n' ' '))
	./push_swap $(NUMBERS) | ./checker_Mac $(NUMBERS)
	@echo "********************"

testr5: $(NAME)
	@echo "******** RUNNING TEST [1, 5]************"
	$(eval NUMBERS = $(shell seq 1 5 | sort -R | tail -n 5 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo "./push_swap $(NUMBERS) | wc -l"
	@echo "********************"

testr6: $(NAME)
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 6 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo "********************"

testr7: $(NAME)
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 7 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo "********************"

testr8: $(NAME)
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 8 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo "********************"
testr10: $(NAME)
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 10 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@echo "********************"
t100: $(NAME)
	@echo "******** RUNNING TEST************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 100 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@./push_swap $(NUMBERS) | wc -l
	@echo "./push_swap $(NUMBERS) | wc -l"
	@echo "********************"

t500: $(NAME)
	@echo "******** RUNNING TEST************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 500 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@./push_swap $(NUMBERS) | wc -l
	@echo "./push_swap $(NUMBERS) | wc -l"
	@echo "********************"

leaks:
	@echo "******** RUNNING TEST [21 1 5]************"
	$(eval NUMBERS = 21 1 5)
	leaks --atExit -- ./push_swap $(NUMBERS)
	@echo "********************"

ran10: $(NAME)
	@echo "******** RUNNING x:in:N RANDOM NUMBERS  || x = [-2000, 2000] || N = [1, 10]************"
	$(eval SIZE = $(shell seq 1 10 | sort -R | tail -n 1 | tr '\n' ' '))
	$(eval NUMBERS = $(shell seq 1 10 | sort -R | tail -n $(SIZE) | tr '\n' ' '))
	./push_swap $(NUMBERS) | ./checker_Mac $(NUMBERS)
	@echo size $(SIZE)
	@echo "./push_swap $(NUMBERS) | wc -l"
	@echo "********************"

randoml: $(NAME)
	@echo "******** RUNNING x:in:N RANDOM NUMBERS  || x = [-2000, 2000] || N = [1, 10]************"
	$(eval SIZE = $(shell seq 1 10 | sort -R | tail -n 1 | tr '\n' ' '))
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n $(SIZE) | tr '\n' ' '))
	leaks --atExit -- ./push_swap $(NUMBERS)
	@echo "********************"

ran30: $(NAME)
	@echo "******** RUNNING TEST ************"
	$(eval SIZE = $(shell seq 10 30 | sort -R | tail -n 1 | tr '\n' ' '))
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n $(SIZE) | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@./push_swap $(NUMBERS) | wc -l
	@echo size $(SIZE)
	@echo "./push_swap $(NUMBERS) | wc -l"
	@echo "********************"

ran50: $(NAME)
	@echo "******** RUNNING TEST ************"
	$(eval SIZE = $(shell seq 20 50 | sort -R | tail -n 1 | tr '\n' ' '))
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n $(SIZE) | tr '\n' ' '))
	./push_swap $(NUMBERS)
	@./push_swap $(NUMBERS) | wc -l
	@echo size $(SIZE)
	@echo "./push_swap $(NUMBERS) | wc -l"
	@echo "********************"

ran100: $(NAME)
	@echo "******** RUNNING TEST ************"
	$(eval NUMBERS = $(shell seq -10000 10000 | sort -R | tail -n 100 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	./push_swap $(NUMBERS) | wc -l

ran500: $(NAME)
	@echo "******** RUNNING TEST ************"
	$(eval NUMBERS = $(shell seq -10000 10000 | sort -R | tail -n 500 | tr '\n' ' '))
	./push_swap $(NUMBERS)
	./push_swap $(NUMBERS) | wc -l

ranl100: $(NAME)
	@echo "******** RUNNING TEST ************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 100 | tr '\n' ' '))
	leaks --atExit -- ./push_swap $(NUMBERS)
	@echo "./push_swap $(NUMBERS) | wc -l"

ranl500: $(NAME)
	@echo "******** RUNNING TEST ************"
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 500 | tr '\n' ' '))
	leaks --atExit -- ./push_swap $(NUMBERS)
	@echo "./push_swap $(NUMBERS) | wc -l"

randombl: $(NAME)
	@echo "******** RUNNING TEST ************"
	$(eval SIZE = $(shell seq 1 20 | sort -R | tail -n 1 | tr '\n' ' '))
	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n $(SIZE) | tr '\n' ' '))
	leaks --atExit -- ./push_swap $(NUMBERS)
	@echo "********************"
#	$(eval NUMBERS = $(shell seq -2000 2000 | sort -R | tail -n 3 | tr '\n' ' '))
#	./push_swap $(shell seq -2000 2000 | sort -R | tail -n 3 | tr '\n' ' ')


PHONY : all re clean fclean sclean

#ARG=$(seq 1 100000 | sort -R | tr ' ' '\n' | tail -500); ./push_swap $ARG | wc -l
