# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhossan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 20:42:53 by akhossan          #+#    #+#              #
#    Updated: 2019/07/03 20:42:56 by akhossan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Fdf

all: $(NAME)

$(NAME):
	gcc main.c -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all 
