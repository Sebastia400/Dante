##
## EPITECH PROJECT, 2021
## d10
## File description:
## description
##

OBJ = $(SRCS_C:.c=.o)

LIB = -L./lib/my -lmy

SFLAGS = -std=c99 -lncurses

SRC		=	sources/

SRC_C	=	main.c 				\
			basic_func.c 		\
			fill_borders.c 		\
			func_solve.c		\
			init_func.c			\
			map_func.c			\
			random_direction.c	\
			perfect_imperfect.c	\
			check_vertical.c

SRCS_C	= 	$(addprefix $(SRC), $(SRC_C))

CFLAGS = -I./include -g

NAME = generator

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(SFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
	make clean
