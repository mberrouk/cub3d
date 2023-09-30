# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberrouk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 21:57:30 by mberrouk          #+#    #+#              #
#    Updated: 2023/09/30 23:45:31 by mberrouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

PARS = parsfile/

SRC = main.c $(PARS)check_errors.c $(PARS)str_utils.c $(PARS)get_next_line.c $(PARS)parsing.c\
	  $(PARS)ft_atoi.c $(PARS)linked_list.c $(PARS)initial_parse.c $(PARS)check_errors_utils.c\
	  $(PARS)parsing_utils.c $(PARS)str_utils_1.c

CC = gcc

CFLAG = -Wall -Wextra -Werror -g3 -fsanitize=address 

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAG) $(SRC) -o $(NAME)

clean :
	rm $(NAME)

fclean : clean

re : fclean all 
