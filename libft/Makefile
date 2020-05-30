# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalome <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 18:19:22 by jsalome           #+#    #+#              #
#    Updated: 2020/05/28 22:53:41 by Artur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = ./srcs/
SRC =       ft_arrnew.c\
            ft_atoi.c\
            ft_bzero.c\
            ft_isalnum.c\
            ft_isalpha.c\
            ft_isascii.c\
            ft_isdigit.c\
            ft_isprint.c\
            ft_itoa.c\
            ft_lstadd.c\
            ft_lstdel.c\
            ft_lstdelone.c\
            ft_lstiter.c\
            ft_lstmap.c\
            ft_lstnew.c\
            ft_lstnull.c\
            ft_memalloc.c\
            ft_memccpy.c\
            ft_memchr.c\
            ft_memcmp.c\
            ft_memcpy.c\
            ft_memdel.c\
            ft_memmove.c\
            ft_memset.c\
            ft_putchar.c\
            ft_putchar_fd.c\
            ft_putendl.c\
            ft_putendl_fd.c\
            ft_putnbr.c\
            ft_putnbr_fd.c\
            ft_putstr.c\
            ft_putstr_fd.c\
            ft_strcat.c\
            ft_strchr.c\
            ft_strclr.c\
            ft_strcmp.c\
            ft_strcpy.c\
            ft_strdel.c\
            ft_strdup.c\
            ft_strequ.c\
            ft_striter.c\
            ft_striteri.c\
            ft_strjoin.c\
            ft_strlcat.c\
            ft_strlen.c\
            ft_strmap.c\
            ft_strmapi.c\
            ft_strncat.c\
            ft_strncmp.c\
            ft_strncpy.c\
            ft_strnequ.c\
            ft_strnew.c\
            ft_strnstr.c\
            ft_strrchr.c\
            ft_strsplit.c\
            ft_strsplit_arrc.c\
            ft_strstr.c\
            ft_strstr_valid.c\
            ft_strsub.c\
            ft_strtrim.c\
            ft_tolower.c\
            ft_toupper.c\
            ft_swap.c\
            get_next_line.c\
            ft_wordcounter.c\
            ft_strdup_till_char.c\
            ft_skipnchars.c\
            ft_strsubptr.c\
            ft_strjoinf.c

OBJ = $(SRC:.c=.o)
OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

INC = libft.h get_next_line.h
INC_DIR = ./includes/
INCS = $(addprefix $(INC_DIR), $(INC))

FLAGS = -g -Wall -Werror -Wextra -O3 -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
		@ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
		clang $(FLAGS) -o $@ -c $<

clean:
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
