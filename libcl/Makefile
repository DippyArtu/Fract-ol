NAME = libcl.a

SRC_DIR = ./srcs/
SRC =		assembly.c\
			build.c\
			clean_up.c\
			execute_kernel.c\
			get_dev_info.c\
			init_cl.c\
			mandelbrot_buffs.c\
			julia_buffs.c\
			buddhabrot_buffs.c

OBJ = $(SRC:.c=.o)
OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

INC = 		libcl.h\
			cl_structs.h\
			cl_user_structs.h
INC_DIR = ./includes/

LIB_INC = libft.h
LIBFT_INC_DIR = ../libft/includes/

FRACT_DEF_INC = 	fract_defines.h\
					fract_structs.h

FRACT_DEF_INC_DIR = ../includes/
FRACT_DEF_INCS = $(addprefix $(FRACT_DEF_INC_DIR), $(FRACT_DEF_INC))

LIB_INCS = $(addprefix $(LIBFT_INC_DIR), $(LIB_INC))
INCS = $(addprefix $(INC_DIR), $(INC))

FLAGS = -g -Wall -Werror -Wextra -I$(INC_DIR) -I$(LIBFT_INC_DIR) -I$(FRACT_DEF_INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
		@ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) $(FRACT_DEF_INCS)
		clang $(FLAGS) -o $@ -c $<

clean:
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re