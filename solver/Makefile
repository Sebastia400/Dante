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

SRC_C	=	main.c				\
			connect_forks.c		\
			connect_forks2.c	\
			check_path.c		\
			check_map.c			\
			get_info.c 			\
			ini_func.c			\
			ini_linked.c		\
			fork_func.c			\
			fork_func2.c		\
			linked_func.c		\
			print.c				\
			path_func.c			\
			save_functions.c	\
			basicfunctions.c	\
			basic_functions_2.c	\
			func_solve.c		\
			func_solve_2.c		\
			func_solve_3.c		\
			save_linked.c		\
			movments_solve.c	\
			str_word_array.c

SRCS_C	= 	$(addprefix $(SRC), $(SRC_C))

CFLAGS = -I./include -g

NAME = solver

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(SFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
	make clean
