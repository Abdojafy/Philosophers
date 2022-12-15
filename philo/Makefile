# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 19:32:57 by ajafy             #+#    #+#              #
#    Updated: 2022/12/13 19:18:54 by ajafy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philo.c ft_parsing.c ft_create_lst.c routine.c philo_utils.c philo_utils_check.c destroy.c ft_init.c ft_liste.c

OBJ = $(SRC:.c=.o)

CC = cc

NAME = philo

CFLAGS = -Wall -Wextra -Werror -pthread

HEADER = philo.h

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) 
	@echo "Philo Maked"

clean :
	@rm -rf $(OBJ)
	@echo "Clean"

fclean : clean
	@rm -rf $(NAME)

re : fclean all