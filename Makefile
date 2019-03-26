# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 19:34:44 by ielmoudn          #+#    #+#              #
#    Updated: 2019/03/05 18:17:55 by mzahir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = *.c

HEADS = fdf.h

FRAMEWORK = -lmlx -framework OpenGL -framework Appkit

FLAGS = -Wall -Wextra -Werror

all:  $(NAME)

$(NAME) :
	make -C libft
	gcc $(FLAGS) -c $(SRCS) $(HEADS)
	gcc -o $(NAME) *.o libft/libft.a libmlx.a $(FRAMEWORK)

clean :
	make clean -C libft
	rm -rf *.o *.dSYM *.gch

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all
