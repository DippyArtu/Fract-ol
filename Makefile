# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/06 17:45:47 by jsalome           #+#    #+#              #
#    Updated: 2020/05/27 21:14:53 by Artur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = ./srcs/
SRC = 	fractol.c\
		draw_image.c\
		init.c\
		calculate_mandelbrot.c\
		calculate_julia.c\
		errors.c\
		menu.c\
		view_control.c\
		mouse_control.c\
		utils.c\
		init_fracts.c\
		julia_transform.c\
		clean_up.c\
		calculate_buddhabrot.c\
		buddhabrot_tools.c

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

COMPLEX_OBJ = *.o
COMPLEX_OBJ_DIR = ./libcomplex/obj/
COMPLEX_OBJS = $(addprefix $(COMPLEX_OBJ_DIR), $(COMPLEX_OBJ))
COMPLEX_SRC_DIR = ./libcomplex/srcs/
COMPLEX_INC = libcomplex.h
COMPLEX_INC_DIR = ./libcomplex/includes/
COMPLEX_INCS = $(addprefix $(COMPLEX_INC_DIR), $(COMPLEX_INC))

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

LIBRARIES = -framework OpenGL -framework AppKit -framework OpenCL -lpthread

FLAGS = -g -Wall -Wextra -Werror -I$(COMPLEX_INC_DIR) -I$(INC_DIR) -I$(LIB_INC_DIR) -I$(MLX_LIB_DIR) -I$(CL_INC_DIR)

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJ_DIR) $(LIB_OBJS) $(CL_OBJS) $(COMPLEX_OBJS) $(OBJS)
		@clang $(OBJS) ./libft/libft.a ./libcl/libcl.a ./libcomplex/libcomplex.a $(MLX_LIB) -o $(NAME) $(LIBRARIES)

$(OBJ_DIR):
		@mkdir -p $@
		@mkdir -p $(LIB_OBJ_DIR)
		@mkdir -p $(CL_OBJ_DIR)
		@mkdir -p $(COMPLEX_OBJ_DIR)

$(LIB_OBJ_DIR)%.o: $(LIB_SRC_DIR)%.c $(LIB_INCS)
		@make -C libft

$(CL_OBJ_DIR)%.o: $(CL_SRC_DIR)%.c $(CL_INCS)
		@make -C libcl

$(COMPLEX_OBJ_DIR)%.o: $(COMPLEX_SRC_DIR)%.c $(COMPLEX_INCS)
		@make -C libcomplex

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
		clang $(FLAGS) -o $@ -c $<

$(MLX_LIB_DIR)%.a:
		@make -sC $(MLX_LIB_DIR)

clean:
		@make clean -C libft
		@make clean -C libcl
		@make clean -C libcomplex
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean: clean
		@make fclean -C libft
		@make fclean -C libcl
		@make fclean -C libcomplex
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
