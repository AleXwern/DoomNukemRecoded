# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 10:42:05 by alexwern          #+#    #+#              #
#    Updated: 2024/05/02 21:18:43 by AleXwern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= werdoom.exe
FLAG	= -m64 -Wall -Wextra -Werror -std=c++17
SRCFILE	= 
OBJ		= ./obj/main.o
LIBFT	= -L ./Libft/build -lft \
			C:/SDL/SDL2-2.0.12/lib/x64/SDL2.lib
INCLS	= -I ./includes -I Libft/includes -I ./tests -I wordwrap/includes -I romannumerals/includes -I queue/includes -I primefactors/includes -I mastermind/includes -I sort/includes -I catch2/extras
GREEN	= \033[0;32m
PURPLE	= \033[0;35m
STOP	= \033[0m
TEMP0	= 0

.PHONY: all clean fclean re

all: $(NAME)

./build/%.exe:./obj/%.o
	@echo "Compiling $(GREEN)$@$(STOP)"
	g++ $(FLAG) -o $@ $(INCLS) $< $(addprefix $(subst obj/,,$(subst _test.o,,$<))/,$(subst _test,,$<)) $(CATCH) $(LIBFT)

$(LIBFT):
	@make -C Libft

sources:
	@make -C code

folders:
	@mkdir -p build
	@mkdir -p obj

$(NAME): folders $(LIBFT) sources $(OBJ)
	@g++ -o $(NAME) ./obj/* $(LIBFT)

clean:
	@make -C code clean
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf ./obj

fclean: clean
	@rm $(NAME)
	@make -C code fclean
	@/bin/rm -rf ./build
	@make -C Libft fclean

re: fclean all
