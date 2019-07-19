# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhossan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 20:42:53 by akhossan          #+#    #+#              #
#    Updated: 2019/07/19 11:16:29 by akhossan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	Fdf

LFT		:= 	-lft -L./libft

LIBS	:=	-lmlx -framework OpenGl -framework Appkit

CFLAGS	:=	-Werror -Wextra -Wall

GNL		:=	gnl/get_next_line.c 

all: $(NAME)

$(NAME):
	@make re -C libft && make clean -C libft
	#@printf "\033[91mLibft done\n"
	@gcc $(CFALGS) dis_pixels.c draw.c read_map.c main.c $(GNL) $(LFT) $(LIBS) -o $(NAME)

clean:
	@make clean -C libft
	@/bin/rm -rf *.o

fclean: clean
	@make -C libft fclean
	@/bin/rm -rf $(NAME)

re: fclean all 
