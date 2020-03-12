# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/06 17:45:47 by jsalome           #+#    #+#              #
#    Updated: 2020/03/11 18:09:15 by Artur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = ./srcs/
SRC = 	fractol.c\
		draw_image.c\
		init.c\
		calculate_fractal.c\
		formulas.c\
		color_managment.c\
		errors.c\
		menu.c\
		view_control.c\
		mouse_control.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ = $(SRC:.c=.o)
OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

INC = fractol.h
INC_DIR = ./includes/
INCS = $(addprefix $(INC_DIR), $(INC))

LIB_OBJ = *.o
LIB_OBJ_DIR = ./libft/obj/
LIB_OBJS = $(addprefix $(LIB_OBJ_DIR), $(LIB_OBJ))
LIB_SRC_DIR = ./libft/srcs/
LIB_INC = libft.h get_next_line.h
LIB_INC_DIR = ./libft/includes/
LIB_INCS = $(addprefix $(LIB_INC_DIR), $(LIB_INC))
MLX_LIB_DIR = ./minilibx_macos/
MLX_LIB = ./minilibx_macos/libmlx.a

LIBRARIES = -framework OpenGL -framework AppKit
#-lpthread
FLAGS = -g -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_INC_DIR) -I$(MLX_LIB_DIR)

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJ_DIR) $(LIB_OBJS) $(OBJS)
		@gcc $(OBJS) ./libft/libft.a $(MLX_LIB) -o $(NAME) $(LIBRARIES)

$(OBJ_DIR):
		@mkdir -p $@
		@mkdir -p $(LIB_OBJ_DIR)

$(LIB_OBJ_DIR)%.o: $(LIB_SRC_DIR)%.c $(LIB_INCS)
		@make -C libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
		gcc $(FLAGS) -o $@ -c $<

$(MLX_LIB_DIR)%.a:
		@make -sC $(MLX_LIB_DIR)

clean:
		@make clean -C libft
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
