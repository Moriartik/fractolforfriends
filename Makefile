# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghar <aghar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 18:00:45 by aghar             #+#    #+#              #
#    Updated: 2020/08/05 16:45:40 by aghar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol 

FLAGS = -Wall -Werror -Wextra  -O3 -ffast-math
LIBRARIES = -lmlx  -lm -lft -L$(LIBFT_D) -L$(MINILIBX_D) -framework OpenGL -framework AppKit
INCLUDES = -I./ -I$(LIBFT_D) -I$(MINILIBX_D) 

LIBFT = $(LIBFT_D)libft.a 
LIBFT_D = ./libft/  

MINILIBX = $(MINILIBX_D)libmlx.a 
MINILIBX_D = ./minilibx/ 

HEADERS = fractol.h keys.h

SRC = main.c fractal.c win.c color.c viewport.c palette.c image.c draw.c keyboard.c mouse.c zoom.c mandelbrot.c julia.c menu.c tree.c exponentn.c burningship.c

OBJ = main.o fractal.o win.o color.o viewport.o palette.o image.o draw.o keyboard.o mouse.o zoom.o mandelbrot.o julia.o menu.o tree.o exponentn.o burningship.o
all: $(NAME) 

$(NAME): $(LIBFT) $(MINILIBX) 
	@gcc $(FLAGS) -I ./ -c $(SRC)
	@gcc $(FLAGS) -g $(LIBRARIES) $(INCLUDES)  -o $(NAME) $(OBJ)

$(LIBFT): 
	@$(MAKE) -sC $(LIBFT_D) 

$(MINILIBX): 
	@$(MAKE) -sC $(MINILIBX_D) 

clean: 
	@$(MAKE) -sC $(LIBFT_D) clean 
	@$(MAKE) -sC $(MINILIBX_D) clean 
	@rm -rf $(OBJ)

fclean: clean 
	@rm   -f ./libft/libft.a
	@rm   -f $(NAME)
re: 
	@$(MAKE) fclean 
	@$(MAKE) all