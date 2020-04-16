# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/06 17:45:47 by jsalome           #+#    #+#              #
#    Updated: 2020/04/13 15:17:09 by Artur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = ./srcs/
SRC = 	fractol.c\
		draw_image.c\
		init.c\
		calculate_fractal.c\
		errors.c\
		menu.c\
		view_control.c\
		mouse_control.c\
		color_control.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ = $(SRC:.c=.o)
OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

INC_DIR = ./includes/
INC = 	fractol.h\
		fract_structs.h\
		fract_defines.h

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

CL_OBJ = *.o
CL_OBJ_DIR = ./libcl/obj/
CL_OBJS = $(addprefix $(CL_OBJ_DIR), $(CL_OBJ))
CL_SRC_DIR = ./libcl/srcs/

CL_INC = 	libcl.h\
			cl_structs.h\
			cl_user_structs.h\
			cl_errors.h

CL_INC_DIR = ./libcl/includes/
CL_INCS = $(addprefix $(CL_INC_DIR), $(CL_INC))

LIBRARIES = -framework OpenGL -framework AppKit -framework OpenCL

FLAGS = -g -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_INC_DIR) -I$(MLX_LIB_DIR) -I$(CL_INC_DIR)

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJ_DIR) $(LIB_OBJS) $(CL_OBJS) $(OBJS)
		@gcc $(OBJS) ./libft/libft.a ./libcl/libcl.a $(MLX_LIB) -o $(NAME) $(LIBRARIES)

$(OBJ_DIR):
		@mkdir -p $@
		@mkdir -p $(LIB_OBJ_DIR)
		@mkdir -p $(CL_OBJ_DIR)

$(LIB_OBJ_DIR)%.o: $(LIB_SRC_DIR)%.c $(LIB_INCS)
		@make -C libft

$(CL_OBJ_DIR)%.o: $(CL_SRC_DIR)%.c $(CL_INCS)
		@make -C libcl

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
		clang $(FLAGS) -o $@ -c $<

$(MLX_LIB_DIR)%.a:
		@make -sC $(MLX_LIB_DIR)

clean:
		@make clean -C libft
		@make clean -C libcl
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean: clean
		@make fclean -C libft
		@make fclean -C libcl
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
