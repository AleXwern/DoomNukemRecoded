# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 19:21:06 by AleXwern          #+#    #+#              #
#    Updated: 2024/09/02 01:36:05 by AleXwern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCFLD	= main
GREEN	= \033[0;32m
PURPLE	= \033[0;35m
STOP	= \033[0m
GCC		= g++

.PHONY: all clean fclean re

all:
	@make -C main
	@make -C map
	@make -C gameloop
	@make -C render

clean:
	@make -C main clean
	@make -C map clean
	@make -C gameloop clean
	@make -C render clean

fclean: clean
	@make -C main fclean
	@make -C map clean
	@make -C gameloop clean
	@make -C render clean

re: fclean all
